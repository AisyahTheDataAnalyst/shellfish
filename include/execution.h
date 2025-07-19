/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:40:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/19 23:08:43 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <fcntl.h> // open
# include <stdlib.h> // getenv, malloc, free, exit, NULL
# include <stdio.h> // printf, perror
# include <unistd.h> // getcwd
# include <stdbool.h> // bool
# include <signal.h> //signal, kill
# include <sys/wait.h> // wait, waitpid
# include <readline/readline.h>
# include <readline/history.h> // add_history
# include "minishell.h"
# include "libft.h"
# include "token.h"
# include "ast.h"
// <readline/readline.h> 
// => readline, rl_clear_history
// => rl_on_new_line, rl_replace_line, rl_redisplay

extern int				g_signal;
typedef enum token_type	t_type;

# define READ 0
# define WRITE 1
# define PERMISSION_DENIED 1
# define CMD_NOT_FOUND 127

typedef struct s_process
{
	char	**splitted_path;
	int		infile;
	int		outfile;
	int		dupped_stdin;
	int		dupped_stdout;
	char	**limiters;
	int		limiter_index;
	int		total_hd;
	bool	pipe_flag;
	int		heredoc_fd;
}	t_process;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	char 			**envp_array;
// 	char 			*export_name;
// 	char			*export_value;
// }			t_list;

typedef struct s_exc
{
	t_process	*process;
	t_list		*exec;
	t_token		*token;
	t_ast		*ast;
	t_data		*data;
	int			exit_code;
}	t_exc;

// execution
void	execution(t_ast *ast, t_exc *exc);
void	exec_pipe(t_ast *ast, t_exc *exc);
void	exec_redirection(t_ast *ast, t_exc *exc);
void	combine_all_heredoc(t_ast *ast, t_exc *exc);
int		reset_cursor_heredocfd(t_exc *exc);
void	rd_append(t_ast *ast, t_exc *exc);
void	rd_in(t_ast *ast, t_exc *exc);
void	rd_out(t_ast *ast, t_exc *exc);
void	rd_heredoc(t_ast *ast, t_exc *exc);
void	exec_word(t_ast *ast, t_exc *exc);
void	dupping_stdin_stdout(t_exc *exc);
void	dup2_close_infile_outfile(t_exc *exc);
void	close_infile_outfile_parent(t_exc *exc);
void	reset_stdin_stdout_unlink_heredocfd(t_exc *exc);

// built_ins
void	built_ins(char **av, t_exc *exc);
int		is_bi(char **args);
void	exec_builtin(t_ast *ast, t_exc *exc);
void	bi_cd(char **av, t_exc *exc);
void	bi_echo(char **av, t_exc *exc);
void	bi_env(t_exc *exc);
void	bi_exit(char **av, t_exc *exc);
void	bi_export(char **av, t_exc *exc);
void	export_add(char **av, t_exc *exc);
void	export_only(t_list *exec);
size_t	longer(int len_1, int len_2);
int		calculate_name_len(char **temp_array, int i);
void	bi_pwd(char **av, t_exc *exc);
void	bi_unset(char **av, t_exc *exc);

//utils
	//free.c
void	free_array(char **s);
void	free_temp_list(t_list *temp_list);
void	freeing(t_exc *exc);
void	free_before_readline(t_exc *exc);

	// init.c
void	get_splitted_path(t_process *process);
void	envp_to_envparray(char **envp, t_list *exec);
int		total_heredocs(t_token *token);
void	mallocing_heredoc(t_exc *exc);

	//reset_signal.c
void	signals_for_heredoc(void);
void	reset_signals(void);
void	reset_before_readline(t_exc *exc);

	//signals.c
void	handle_cntrl_c(int sig);
void	handle_cntrl_d(int sig);
void	handle_cntrl_c_heredoc(int sig);
void	handle_cntrl_d_heredoc(int sig);

#endif