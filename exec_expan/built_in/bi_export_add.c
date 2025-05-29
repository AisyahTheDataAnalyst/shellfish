/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:44:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/28 11:06:52 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			bi_export(char **av, char **envp, t_list *exec);
// static void		export_add_ori(char **av, char **envp, t_list *exec);
static void		export_add(char **av, t_list *exec);

void	bi_export(char **av, char **envp, t_list *exec)
{
	if (ft_strncmp(av[0], "export", 6) == 0 && ft_strchr(av[1], '='))
	{
		if (!exec->envp_array)
			envp_to_envparray(envp, exec);
		export_add(av, exec);
	}
	else if (ft_strncmp(av[0], "export", 6) == 0 && !av[1])
		export_only(envp, exec);
}

// tested
static void	export_add(char **av, t_list *exec)
{
	int		i;
	size_t	size;
	char	**temp;

	size = ft_array_size(exec->envp_array);
	temp = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (exec->envp_array[i])
	{
		temp[i] = ft_strdup(exec->envp_array[i]);
		i++;
	}
	temp[i++] = ft_strdup(av[1]);
	temp[i] = NULL;
	free_double_array(exec->envp_array);
	exec->envp_array = temp;
}

// THIS IS THE LATEEST
// static void	export_only_array(t_list *exec)
// {
// 	bool equal_flag;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (exec->envp_array[i])
// 	{
// 		printf("declare -x ");
// 		j = 0;
// 		equal_flag = false;
// 		while (exec->envp_array[i][j])
// 		{
// 			if (exec->envp_array[i][j] == '=' && equal_flag == false)
// 			{
// 				equal_flag = true;
// 				printf("%c\"", exec->envp_array[i][j++]);
// 			}
// 			else if (exec->envp_array[i][j + 1] == '\0')
// 				printf("%c\"\n", exec->envp_array[i][j++]);
// 			else
// 				printf("%c", exec->envp_array[i][j++]);
// 		}
// 		i++;
// 	}
// 	printf("testing only_array\n");
// }
// void export_add_ori(char **av, char **envp, t_list *exec)
// {
// 	int i;
// 	i = 0;
// 	while (envp[i])
// 		i++;
// 	exec->envp_list = NULL;
// 	i = 0;
// 	while (envp[i])
// 	{
// 		ft_lstadd_back(&exec->envp_list, ft_lstnew(envp[i]));
// 		i++;
// 	}
// 	ft_lstadd_back(&exec->envp_list, ft_lstnew(av[2]));
// 	transform_exec_ll_to_array(exec);
// 	// bawah ni nnti padam
// 	i = 0;
// 	while (exec->envp_array[i])
// 	{
// 		printf("%s\n", exec->envp_array[i]);
// 		i++;
// 	}
// }
//tested
// static void	export_add_ori(char **av, char **envp, t_list *exec)
// {
// 	size_t	size;
// 	int		i;

// 	size = ft_array_size(envp);
// 	exec->envp_array = malloc(sizeof(char *) * (size + 2));
// 	i = 0;
// 	while (envp[i])
// 	{
// 		exec->envp_array[i] = ft_strdup(envp[i]);
// 		i++;
// 	}
// 	exec->envp_array[i++] = ft_strdup(av[1]);
// 	exec->envp_array[i] = NULL;
// 	printf("testing add_ori\n");
// }

// void export_add(char **av, t_list *exec)
// {
// 	int i;
// 	i = 0;
// 	while (exec->envp_array[i])
// 		i++;
// 	exec->envp_list = NULL;
// 	i = 0;
// 	while (exec->envp_array[i])
// 	{
// 		ft_lstadd_back(&exec->envp_list, ft_lstnew(exec->envp_array[i]));
// 		i++;
// 	}
// 	ft_lstadd_back(&exec->envp_list, ft_lstnew(av[2]));
// 	transform_exec_ll_to_array(exec);
// 	// bawah ni nnti padam
// 	i = 0;
// 	while (exec->envp_array[i])
// 	{
// 		printf("%s\n", exec->envp_array[i]);
// 		i++;
// 	}
// }
