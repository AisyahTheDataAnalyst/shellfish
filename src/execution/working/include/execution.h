/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:40:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:11:51 by aimokhta         ###   ########.fr       */
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
// <readline/readline.h> 
// => readline, rl_clear_history
// => rl_on_new_line, rl_replace_line, rl_redisplay

# define READ 0
# define WRITE 1
# define CMD_NOT_FOUND 127

extern int	g_signal;

// ---------------------------------------------
//		TOKENIZATION & PARSING'S STRUCTS
// ---------------------------------------------

typedef enum token_type
{
	TOKEN_WORD, // argument or commands
	TOKEN_HEREDOC, // <<
	TOKEN_APPEND, // >>
	TOKEN_REDIRECT_IN, // <
	TOKEN_REDIRECT_OUT, // >
	TOKEN_PIPE, // |
}			t_type;

typedef struct s_word_arr
{
	int		word_count;
	char	**array;
}				t_word_arr;

typedef struct s_token
{
	int				index;
	t_type			token_type;
	char			**basin_buff;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct s_ast
{
	t_token			*token;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

typedef struct s_data
{
	int			index;
	t_token		*token;
	t_word_arr	word;
	t_ast		*ast;
}				t_data;

// ---------------------------------------------
//				EXECUTION'S STRUCTS
// ---------------------------------------------

typedef struct s_process
{
	pid_t	last_pid;
	char	**splitted_path;
	int		infile;
	int		outfile;
	char	**limiters;
	int		limiter_index;
}	t_process;

typedef struct s_exc
{
	t_token		*token;
	t_list		*exec;
	t_ast		*ast;
	t_process	*process;
	int			exit_code;
}	t_exc;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	char 			**envp_array;
// 	char 			*export_name;
// 	char			*export_value;
// }			t_list;

// ---------------------------------------------
// 
//					EXECUTION's
//					FUNCTIONS
// 
// ---------------------------------------------

// built_ins
int		built_ins(char **av, t_exc *exc);
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