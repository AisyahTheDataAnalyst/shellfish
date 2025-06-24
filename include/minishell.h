/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:40:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/23 13:50:43 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h> // open
# include <stdlib.h> // getenv, malloc, free, exit, NULL
# include <stdio.h> // printf, perror
# include <limits.h> // PATH_MAX
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

typedef enum token_type
{
	TOKEN_WORD, // argument or commands
	TOKEN_HEREDOC, // <<
	TOKEN_APPEND, // >>
	TOKEN_REDIRECT_IN, // <
	TOKEN_REDIRECT_OUT, // >
	TOKEN_PIPE, // |
}			t_type;

typedef struct s_token
{
	int				index;
	t_type			token_type;
	char			**basin_buff;
	struct s_token	*next;
}					t_token;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	char 			**envp_array;
// 	char			**splitted_path;
// 	char 			*export_name;
// 	char			*export_value;
// }			t_list;

typedef struct s_data
{
	t_token	*token;
	t_list	*exec;
	int		exit_code;
}	t_data;

// built_ins
void	built_ins(char **av, t_data *data);
void	bi_cd(char **av, t_data *data);
void	bi_echo(char **av, t_data *data);
void	bi_env(t_data *data);
void	bi_exit(char **av, t_data *data);
void	bi_export(char **av, t_data *data);
void	export_add(char **av, t_data *data);
void	export_only(t_list *exec);
size_t	longer(int len_1, int len_2);
void	bi_pwd(char **av, t_data *data);
void	bi_unset(char **av, t_data *data);

//utils
	// init.c
void	get_splitted_path(t_list *exec);
void	envp_to_envparray(char **envp, t_list *exec);
	//signals.c
void	handle_cntrl_c(int sig);
void	handle_cntrl_d(int sig);
void	handle_cntrl_c_heredoc(int sig);
void	handle_cntrl_d_heredoc(int sig);
	//free.c
void	freeing(t_list *exec);
void	free_double_array(char **s);
void	free_temp_list(t_list *temp_list);

// redirections
int		redirects(t_token *token);
int		rd_in(t_token *token);
int		rd_out(t_token *token);
int		rd_heredoc(t_token *token);
int		rd_append(t_token *token);

#endif