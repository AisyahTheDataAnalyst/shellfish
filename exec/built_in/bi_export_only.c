/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:32:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/23 13:52:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			export_only(t_list *exec);
static t_list	*tarray_to_tlist(char **temp_array, t_list *temp_list);
static t_list	*ft_lstnew_export(char *name, char *value);
static void		sort_export(t_list *temp_list);
static void		swapped_name_value(t_list *a, t_list *b);

void	export_only(t_list *exec)
{
	char	**temp_array;
	t_list	*temp_list;
	t_list	*curr;

	temp_array = exec->envp_array;
	temp_list = NULL;
	temp_list = tarray_to_tlist(temp_array, temp_list);
	sort_export(temp_list);
	curr = temp_list;
	while (curr)
	{
		printf("declare -x %s=\"%s\"\n", curr->export_name, curr->export_value);
		curr = curr->next;
	}
	free_temp_list(temp_list);
}

static t_list	*tarray_to_tlist(char **temp_array, t_list *temp_list)
{
	char	*name;
	char	*value;
	t_list	*new_node;
	int		i;
	int		name_len;

	i = -1;
	while (temp_array[++i])
	{
		name_len = 0;
		while (temp_array[i][name_len] != '=' && temp_array[i][name_len])
			name_len++;
		name_len = ft_strchr(temp_array[i], '=') - temp_array[i];
		name = ft_substr(temp_array[i], 0, name_len);
		value = ft_strchr(temp_array[i], '=') + 1;
		new_node = ft_lstnew_export(name, value);
		ft_lstadd_back(&temp_list, new_node);
	}
	return (temp_list);
}

static t_list	*ft_lstnew_export(char *name, char *value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->export_name = name;
	// printf("%s\n", name);
	new_node->export_value = value;
	// printf("%s\n", value);
	new_node->next = NULL;
	return (new_node);
}

static void	sort_export(t_list *temp_list)
{
	t_list	*a;
	int		swapped;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		a = temp_list;
		while (a && a->next)
		{
			if (ft_strncmp(a->export_name, a->next->export_name,
					longer(ft_strlen(a->export_name),
						ft_strlen(a->next->export_name))) > 0)
			{
				swapped_name_value(a, a->next);
				swapped = 1;
			}
			a = a->next;
		}
	}
}

static void	swapped_name_value(t_list *a, t_list *b)
{
	char	*temp_name;
	char	*temp_value;

	temp_name = a->export_name;
	temp_value = a->export_value;
	a->export_name = b->export_name;
	a->export_value = b->export_value;
	b->export_name = temp_name;
	b->export_value = temp_value;
}
