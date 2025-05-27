/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:32:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/26 14:11:20 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			export_only(char **envp, t_list *exec);
static t_list	*tarray_to_tlist(char **temp_array, t_list *temp_list);
static t_list	*ft_lstnew_export(char *name, char *value);
static void		sort_export(t_list *temp_list);
static size_t	longer(t_list *a, t_list *b);

// YESS NICE
void	export_only(char **envp, t_list *exec)
{
	char	**temp_array;
	t_list	*temp_list;
	t_list	*curr;

	if (exec->envp_array)
		temp_array = exec->envp_array;
	else
		temp_array = envp;
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
	printf("testing export only\n");
}

static t_list	*tarray_to_tlist(char **temp_array, t_list *temp_list)
{
	char	*name;
	char	*value;
	t_list	*new_node;
	int		i;
	int		j;

	i = 0;
	while (temp_array[i])
	{
		j = 0;
		while (temp_array[i][j] != '=' && temp_array[i][j])
			j++;
		name = malloc(sizeof(char) * (j + 1));
		j = 0;
		while (temp_array[i][j] != '=' && temp_array[i][j])
		{
			name[j] = temp_array[i][j];
			j++;
		}
		name[j] = '\0';
		value = ft_strchr(temp_array[i++], '=') + 1;
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
	new_node->export_value = value;
	new_node->next = NULL;
	return (new_node);
}

static void	sort_export(t_list *temp_list)
{
	t_list	*a;
	t_list	*b;
	int		swapped;
	char	*temp;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		a = temp_list;
		b = a->next;
		while (a && b)
		{
			if (ft_strncmp(a->export_name, b->export_name, longer(a, b)) > 0)
			{
				temp = a->export_name;
				a->export_name = b->export_name;
				b->export_name = temp;
				swapped = 1;
			}
			a = a->next;
			b = a->next;
		}
	}
}

static size_t	longer(t_list *a, t_list *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_strlen(a->export_name);
	len_b = ft_strlen(b->export_name);
	if (len_a > len_b)
		return (len_a);
	return (len_b);
}
