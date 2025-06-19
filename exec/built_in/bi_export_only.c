/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:32:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:21:06 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			export_only(t_list *exec);
static t_list	*tarray_to_tlist(char **temp_array, t_list *temp_list);
static t_list	*ft_lstnew_export(char *name, char *value);
static void		sort_export(t_list *temp_list);
static size_t	longer(char *str1, char *str2);

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

	i = 0;
	while (temp_array[i])
	{
		name_len = 0;
		while (temp_array[i][name_len] != '=' && temp_array[i][name_len])
			name_len++;
		name = malloc(sizeof(char) * (name_len + 1));
		name_len = ft_strchr(temp_array[i], '=') - temp_array[i];
		name = ft_substr(temp_array[i], 0, name_len);
		value = ft_strchr(temp_array[i++], '=') + 1;
		new_node = ft_lstnew_export(name, value);
		ft_lstadd_back(&temp_list, new_node);
	}
	return (temp_list);
}

// static char	*skipping_outer_quotes(char *value)
// {
// 	int		start;
// 	int		len;
// 	char	*new_value;
// 	bool	single_quote;

// 	single_quote = false;
// 	start = -1;
// 	if (value[0] == '"')
// 		while (value[++start])
// 			if (value[start] == '"')
// 				continue ;
// 	else if (value[0] == '\'')
// 	{
// 		single_quote = 
// 		while (value[++start])
// 			if (value[start] == '\'')
// 				continue ;
// 	}
// 	if (value[start] == '\'')
// 	{
// 		single_quote = true;
// 		start++;
// 	}
// 	len = 0;
// 	if (single_quote == false)
// 		len = ft_strchr(value + start, '"') - (value + start);
// 	else
// 		len = ft_strchr(value + start, '\'') - (value + start);
// 	new_value = ft_substr(value + start, 0, len);
// 	return (new_value);
// }

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
			if (ft_strncmp(a->export_name, b->export_name,
					longer(a->export_name, b->export_name)) > 0)
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

static size_t	longer(char *str1, char *str2)
{
	int	str1_len;
	int	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	if (str1_len > str2_len)
		return (str1_len);
	return (str2_len);
}
