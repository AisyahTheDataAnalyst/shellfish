/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:40:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:43:14 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

// built_ins
void	built_ins(char **av, char **envp, t_list *exec);
void	bi_cd(char **av, char **envp, t_list *exec);
void	envp_to_envparray(char **envp, t_list *exec);
void	bi_echo(char **av);
void	bi_env(char **envp, t_list *exec);
void	bi_exit(char **av, t_list *exec);
void	bi_export(char **av, char **envp, t_list *exec);
void	export_only(char **envp, t_list *exec);
void	bi_pwd(char **av);
void	bi_unset(char **av, char **envp, t_list *exec);

// splitted_path.c
void	get_splitted_path(t_list *exec);

//signals.c
void handle_cntrl_c(int sig);
// void handle_cntrl_backslash(int sig);
void handle_cntrl_d(int sig); //, t_list *exec);

//free.c
void	freeing(t_list *exec);
void	free_double_array(char **s);
void	free_temp_list(t_list *temp_list);

#endif