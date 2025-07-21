/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:18:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/21 17:10:29 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void			export_add(char **av, t_exc *exc);
static char		**building_envp_temp(char **vars, t_exc *exc, char **temp);
static int		invalid_export_var(char *var, t_exc *exc);
static int		already_existed_var(char *var, char **temp, int i);
static int		invalid_export_var_helper(char *var, t_exc *exc, \
bool invalid_var_flag);

//you can do this aisyah!
void	export_add(char **av, t_exc *exc)
{
	char	**temp;
	size_t	envp_size;
	size_t	vars_size;

	envp_size = ft_array_size(exc->exec->envp_array);
	vars_size = ft_array_size(av);
	temp = malloc(sizeof(char *) * (envp_size + vars_size + 1));
	temp = building_envp_temp(av, exc, temp);
	free_array(exc->exec->envp_array);
	exc->exec->envp_array = temp;
}

// continue - skip all the other things below it and just continue the loop
static char	**building_envp_temp(char **vars, t_exc *exc, char **temp)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	while (exc->exec->envp_array[++i])
		temp[i] = ft_strdup(exc->exec->envp_array[i]);
	j = 0;
	while (vars[++j])
	{
		if (invalid_export_var(vars[j], exc) == 1)
			continue ;
		else if (already_existed_var(vars[j], temp, i) == -1)
			temp[i++] = ft_strdup(vars[j]);
		else if (already_existed_var(vars[j], temp, i) != -1)
		{
			index = already_existed_var(vars[j], temp, i);
			free(temp[index]);
			temp[index] = ft_strdup(vars[j]);
		}
	}
	temp[i] = NULL;
	return (temp);
}

static int	invalid_export_var(char *var, t_exc *exc)
{
	int		i;
	bool	invalid_var_flag;

	invalid_var_flag = false;
	i = 0;
	if (ft_isalpha(var[i]) == 1 || var[i] == '_')
		i++;
	else
		invalid_var_flag = true;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 1 || var[i] == '_')
			i++;
		else
		{
			invalid_var_flag = true;
			break ;
		}
	}
	if (invalid_export_var_helper(var, exc, invalid_var_flag) == 1)
		return (1);
	return (0);
}

static int	invalid_export_var_helper(char *var, t_exc *exc, \
bool invalid_var_flag)
{
	if (invalid_var_flag == true)
	{
		exc->exit_code = 1;
		ft_putstr_fd("shellfish: export: \'", 2);
		ft_putstr_fd(var, 2);
		ft_putendl_fd("\': not a valid identifier", 2);
		return (1);
	}
	return (0);
}

// buat dia return -1 because if it want to return index
// it must return positive numbers
static int	already_existed_var(char *var, char **temp, int i)
{
	int		j;
	char	*envp_key;
	char	*var_key;
	int		envp_key_len;
	int		var_key_len;

	j = -1;
	while (++j < i)
	{
		envp_key_len = ft_strchr(temp[j], '=') - temp[j];
		envp_key = ft_substr(temp[j], 0, envp_key_len);
		var_key_len = ft_strchr(var, '=') - var;
		var_key = ft_substr(var, 0, var_key_len);
		if (!ft_strncmp(envp_key, var_key, longer(envp_key_len, var_key_len)))
		{
			free(envp_key);
			free(var_key);
			return (j);
		}
		free(envp_key);
		free(var_key);
	}
	return (-1);
}
