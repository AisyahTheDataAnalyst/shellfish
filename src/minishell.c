/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:57:34 by yelu              #+#    #+#             */
/*   Updated: 2025/05/02 21:15:15 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	int_main_init(t_exc *exc, char **envp);
static void	int_main_loop(t_exc *exc);

int g_signal = 0;

int main(int argc, char **argv, char **env)
{
	t_exc	*exc;

	(void)argv;
	// (void)argc;
	if (argc != 1)
	{
		ft_putstr_fd("No such files or directory", 2);
		return (1);
	}
	exc = malloc(sizeof(t_exc));
	int_main_init(exc, env);
	int_main_loop(exc);
	freeing(exc);
	printf("exit\n");
	return (0);
}

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

static void	int_main_loop(t_exc *exc)
{
	t_input_info	b_input;
	t_data			data;

	exc->data = &data; 
	while (1)
	{
		exc->process->input = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
		if (!exc->process->input)
		{
			free(exc->process->input);
			break ;
		}
		if (ft_strncmp(exc->process->input, "\n", 2) > 0)
			add_history(exc->process->input);
		if (!init_tokens(&data, &b_input, exc->process->input))
			continue ;
		if (!init_ast(&data))
			continue ;
		mallocing_heredoc(exc);
		ast_execution(data.root, exc);
		reset_g_signal_code_limiter_index(exc);
		free_before_readline(exc);
		printf("exit_code : %d\n", exc->exit_code);
	}
}





















// static void print_ast(t_ast *node, int depth, char side)
// {
//     const char *arr[] = {
//         "WORD",
//         "HEREDOC",
//         "APPEND",
//         "REDIR_IN",
//         "REDIR_OUT",
//         "PIPE",
//         NULL
//     };

//     if (!node) return;
//     for (int i = 0; i < depth; i++) printf(CYAN"|  "COLOR);
//     printf("%c[%s:%d]\n", side, arr[node->token->token_type], node->token->index);
//     print_ast(node->left, depth + 1, 'L');
//     print_ast(node->right, depth + 1, 'R');
// }

// static void print_tokens(t_token *head)
// {
//     const char *arr[7] = {
//         "WORD",
//         "HEREDOC",
//         "APPEND",
//         "REDIR_IN",
//         "REDIR_OUT",
//         "PIPE",
//         NULL
//     };

//     printf("\n=== Token Linked List ===\n");
//     while (head)
//     {
//         printf("Token index: %d\n", head->index);
//         printf("Token type: %s\n", arr[head->token_type]);
//         if (head->basin_buff)
//         {
//             printf("Token basin_buff content:\n");
//             for (int i = 0; head->basin_buff[i]; i++)
//                 printf("  - %s\n", head->basin_buff[i]);
//         }
//         else
//             printf("Token basin_buff is NULL\n");
//         printf("---------------------------\n");
//         head = head->next;
//     }
//     printf("=== END OF LINKED LIST ===\n");
// }