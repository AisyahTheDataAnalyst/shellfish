/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:40:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/12 14:13:58 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <fcntl.h> // open
# include <stdlib.h> // getenv, malloc, free, exit, NULL
# include <stdio.h> // printf, perror
// # include <limits.h> // PATH_MAX
# include <unistd.h> // getcwd
# include <stdbool.h> // bool
# include <signal.h> //signal, kill
# include <sys/wait.h> // wait, waitpid
# include <readline/readline.h>
# include <readline/history.h> // add_history
# include "libft.h"
// # include "token.h"
// <readline/readline.h> 
// => readline, rl_clear_history
// => rl_on_new_line, rl_replace_line, rl_redisplay

# define READ 0
# define WRITE 1
# define CMD_NOT_FOUND 127

extern int	g_signal;

//----------------------------------------------
//          TOKEN&AST'S STRUCTS
//----------------------------------------------

typedef enum token_type
{
	TOKEN_WORD, // argument or commands
	TOKEN_HEREDOC, // <<
	TOKEN_APPEND, // >>
	TOKEN_REDIRECT_IN, // <
	TOKEN_REDIRECT_OUT, // >
	TOKEN_PIPE, // |
	// token quotes
} t_type;

typedef struct s_word_arr
{
	int		count;
	char	**array;
} t_word_arr;

typedef struct s_token
{
	int index;
	t_type token_type;
	char **basin_buff;
	struct s_token *next;
} t_token;

typedef struct s_ast
{
	t_token     *token;
	struct s_ast *left;
	struct s_ast *right;
} t_ast;

typedef struct s_data
{
	int index;
	t_token     *token;
	t_ast		*root;
	t_word_arr  word;
	char		**split_array;
} t_data;

// ---------------------------------------------
//				EXECUTION'S STRUCTS
// ---------------------------------------------

typedef struct s_process
{
	pid_t	last_pid;
	char	**splitted_path;
	int		infile;
	int		outfile;
	int		dupped_stdin;
	int		dupped_stdout;
	char	**limiters;
	int		limiter_index;
	int		total_hd;
	bool	pipe_flag;
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
	int			exit_code;
}	t_exc;

// ---------------------------------------------
// 
//					EXECUTION's
//					FUNCTIONS
// 
// ---------------------------------------------

// ast_execution
void	ast_execution(t_ast *ast, t_exc *exc);
void	ast_pipe(t_ast *ast, t_exc *exc);
void	ast_redirection(t_ast *ast, t_exc *exc);
void	rd_heredoc(t_ast *ast, t_exc *exc);
int		reset_cursor_heredocfd(int heredoc_fd);
void	rd_append(t_ast *ast, t_exc *exc);
void	rd_in(t_ast *ast, t_exc *exc);
void	rd_out(t_ast *ast, t_exc *exc);
void	ast_word(t_ast *ast, t_exc *exc);
void	dupping_stdin_stdout(t_exc *exc);
void	dup2_close_infile_outfile(t_exc *exc);
void	reset_stdin_stdout_unlink_heredocfd(t_exc *exc);

//fake_ast.c
t_ast	*create_ast_node(char **args, t_type type);
void 	insert_left_node(t_ast *parent, char **args, t_type type);
void	insert_right_node(t_ast *parent, char **args, t_type type);
void	free_ast(t_ast *node);

// built_ins
void	built_ins(char **av, t_exc *exc);
int 	is_bi(char **args);
void	ast_builtin(t_ast *ast, t_exc *exc);
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
void	free_double_array(char **s);
void	free_temp_list(t_list *temp_list);
void	freeing(t_exc *exc);
	// init.c
void	get_splitted_path(t_process *process);
void	envp_to_envparray(char **envp, t_list *exec);
int		total_heredocs(t_token *token);
	//reset_signal.c
void	signals_for_heredoc(void);
void	reset_signals(void);
void	reset_g_signal_code(t_exc *exc);
	//signals.c
void	handle_cntrl_c(int sig);
void	handle_cntrl_d(int sig);
void	handle_cntrl_c_heredoc(int sig);
void	handle_cntrl_d_heredoc(int sig);

#endif