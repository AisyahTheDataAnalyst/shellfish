/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:22 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/13 16:07:03 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	int_main_init(t_exc *exc, char **envp);
static void	int_main_loop(t_exc *exc);
static void mallocing_heredoc(t_exc *exc);

int	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_exc	*exc;
	// t_data	data;

	(void)av;
	if (ac != 1)
		return (1);
	exc = malloc(sizeof(t_exc));
	int_main_init(exc, envp);
	int_main_loop(exc); //, &data);
	freeing(exc);
	printf("exit\n");
	return (0);
}

// do signals outside loop, introducing the action for the signals only, 
// 	if put in the loop, it will be redundant, resetting on every loop
// 	if later you change it overwrite with another signal fn, you reset it, bug.
// ascii 4 = EOT = end of transmission = Cntrl D = EOF
// ascii 3 = ETX = end of text = Cntrl C = SIGINT
// ascii 28 = FS = file separator / QUIT = Cntrl backslash = SIGQUIT
// SIG_IGN = signal ignore = for cntrl backslash
static void	int_main_init(t_exc *exc, char **envp)
{
	ft_bzero(exc, sizeof(t_exc));
	exc->exec = malloc(sizeof(t_list));
	ft_bzero(exc->exec, sizeof(t_list));
	exc->process = malloc(sizeof(t_process));
	ft_bzero(exc->process, sizeof(t_process));
	exc->process->infile = -1;
	exc->process->outfile = -1;
	exc->process->dupped_stdin = -1;
	exc->process->dupped_stdout = -1;
	exc->process->limiters = NULL;
	get_splitted_path(exc->process);
	envp_to_envparray(envp, exc->exec);
	reset_signals();
}

// only add_history if theres not an empty readline
static void	int_main_loop(t_exc *exc) //, t_data *data)
{
	// char	**basin;

	while (1)
	{
		exc->process->input = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
		if (!exc->process->input)
		{
			free_before_readline(exc);
			break ;
		}
		// if (!init_tokens(data, exc->process->input))
		// {
		// 	//free
		// 	continue ;
		// }
		if (ft_strncmp(exc->process->input, "\n", 2) > 0)
			add_history(exc->process->input);
		t_ast *root = create_ast_node((char *[]){NULL}, TOKEN_PIPE);
		insert_left_node(root, (char *[]){NULL}, TOKEN_PIPE);
		insert_right_node(root, (char *[]){"out", NULL}, TOKEN_REDIRECT_OUT);
		insert_left_node(root->right, (char *[]){"wc", "-l", NULL}, TOKEN_WORD);
		insert_left_node(root->left, (char *[]){"export", NULL}, TOKEN_WORD);
		insert_right_node(root->left, (char *[]){"cat", "-e", NULL}, TOKEN_WORD);
		// insert_left_node(root->left, (char *[]){"e3", NULL}, TOKEN_HEREDOC);
		// insert_left_node(root->left->left, (char *[]){"cat", "-e", NULL}, TOKEN_WORD);
		// insert_left_node(root->left, (char *[]){"cat", NULL}, TOKEN_WORD);
		// insert_left_node(root, (char *[]){"out", NULL}, TOKEN_REDIRECT_OUT);
		// insert_left_node(root, (char *[]){"out", NULL}, TOKEN_APPEND);
		// insert_left_node(root->left, (char *[]){"E2", NULL}, TOKEN_HEREDOC);
		// insert_left_node(root->left->left, (char *[]){"append", NULL}, TOKEN_APPEND);
		// insert_left_node(root->left->left->left, (char *[]){"cat", NULL}, TOKEN_WORD);
		// insert_left_node(root->left->left->left, (char *[]){"cat", NULL}, TOKEN_WORD);
		exc->ast = root;
		// t_ast *temp = root;
		// t_ast *temp1 = root;
		// int i = 0;
		// while (temp)
		// {
		// 	printf("node%d : %s\n", i, temp->token->basin_buff[0]);
		// 	temp = temp->left;
		// 	i++;
		// }
		// i = 0;
		// if (temp1)
		// {
		// 	printf("node%d : %s\n", i, temp1->token->basin_buff[0]);
		// 	temp1 = temp1->right;
		// 	i++;
			// printf("node%d : %s\n", i, temp1->token->basin_buff[0]);
			// temp1 = temp1->left;
			// i++;
		// }		
		mallocing_heredoc(exc);
		ast_execution(exc->ast, exc);
		reset_g_signal_code(exc);
		free_before_readline(exc);
		printf("exit_code : %d\n", exc->exit_code);
	}
}

static void mallocing_heredoc(t_exc *exc)
{
	exc->process->total_hd = 0; //total_heredocs(exc->token);
	if (exc->process->total_hd > 0)
	{
		exc->process->limiters = malloc(sizeof(char *) * \
(exc->process->total_hd + 1));
	exc->process->limiters[exc->process->total_hd] = NULL;
	}
}
