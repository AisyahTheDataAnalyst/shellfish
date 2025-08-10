/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:45:55 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/10 09:10:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		bi_cd( char **av, t_exc *exc);
static void	cd_update_env(char *oldpwd, t_list *exec);

// 1024 = enough for most directory path in typical use cases 
// the same number for get_next_line bonus
// must check if !av[1] so that wont pass NULL to ft_strncmp
void	bi_cd(char **av, t_exc *exc)
{
	char	cwd[1024];
	char	*old_pwd;

	exc->exit_code = 0;
	old_pwd = getcwd(cwd, sizeof(cwd));
	if (av[1] && av[2])
	{
		ft_putendl_fd("shellfish: cd: too many arguments", 2);
		exc->exit_code = 1;
	}
	else if (!av[1] || ft_strncmp("~", av[1], 2) == 0)
	{
		if (chdir(getenv("HOME")) == 0)
			cd_update_env(old_pwd, exc->exec);
	}
	else if (chdir(av[1]) == 0)
		cd_update_env(old_pwd, exc->exec);
	else if (chdir(av[1]) == -1)
	{
		ft_putstr_fd("shellfish: cd: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		exc->exit_code = 1;
	}
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
		if (ft_strncmp("PWD=", exec->envp_array[i], 4) == 0)
			temp[i++] = ft_strjoin("PWD=", pwd);
		else if (ft_strncmp("OLDPWD=", exec->envp_array[i], 7) == 0)
			temp[i++] = ft_strjoin("OLDPWD=", oldpwd);
		else
		{
			temp[i] = ft_strdup(exec->envp_array[i]);
			i++;
		}
	}
	temp[i] = NULL;
	free_array(exec->envp_array);
	exec->envp_array = temp;
}
