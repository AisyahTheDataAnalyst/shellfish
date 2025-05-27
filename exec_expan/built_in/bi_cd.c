/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:45:55 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:24:43 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		bi_cd(char **av, char **envp, t_list *exec);
static void	cd_update_env(char *oldpwd, t_list *exec);

// must check if !av[1] so that wont pass NULL to ft_strncmp
void	bi_cd(char **av, char **envp, t_list *exec)
{
	char	cwd[1024];
	char	*prev_path;
	char	*home;

	if (!exec->envp_array)
		envp_to_envparray(envp, exec);
	prev_path = getcwd(cwd, sizeof(cwd));
	home = getenv("HOME");
	if (!av[1] || ft_strncmp("~", av[1], 2) == 0)
		chdir(home);
	else if (chdir(av[1]) == 0)
		cd_update_env(prev_path, exec);
	else if (chdir(av[1]) == -1)
		perror("cd");
}

void	envp_to_envparray(char **envp, t_list *exec)
{
	size_t	size;
	int		i;

	size = ft_array_size(envp);
	exec->envp_array = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (envp[i])
	{
		exec->envp_array[i] = ft_strdup(envp[i]);
		i++;
	}
	exec->envp_array[i] = NULL;
}

// chdir will handle if the directory youre going to is valid or not
// if you are going forward, just strjoin with the directory you want to go to
// you can do this. 
static void	cd_update_env(char *oldpwd, t_list *exec)
{
	char	**temp;
	char	*pwd;
	char	cwd[1024];
	size_t	i;

	pwd = getcwd(cwd, sizeof(cwd));
	i = ft_array_size(exec->envp_array);
	temp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (exec->envp_array[i])
	{
		if (ft_strncmp("PWD", exec->envp_array[i], 3) == 0)
			temp[i++] = ft_strjoin("PWD=", pwd);
		else if (ft_strncmp("OLDPWD", exec->envp_array[i], 6) == 0)
			temp[i++] = ft_strjoin("OLDPWD=", oldpwd);
		else
		{
			temp[i] = ft_strdup(exec->envp_array[i]);
			i++;
		}
	}
	temp[i] = NULL;
	free_double_array(exec->envp_array);
	exec->envp_array = temp;
}
