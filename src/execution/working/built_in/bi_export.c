/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:19:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	bi_export(char **av, t_exc *exc)
{
	if (ft_strncmp(av[0], "export", 6) == 0 && av[1])
	{
		exc->exit_code = 0;
		export_add(av, exc);
	}
	else if (ft_strncmp(av[0], "export", 6) == 0 && !av[1])
	{
		export_only(exc->exec);
		exc->exit_code = 0;
	}
}

size_t	longer(int len_1, int len_2)
{
	if (len_1 > len_2)
		return (len_1);
	return (len_2);
}

int	calculate_name_len(char **temp_array, int i)
{
	int	name_len;

	if (!ft_strchr(temp_array[i], '='))
		name_len = ft_strlen(temp_array[i]);
	else
		name_len = ft_strchr(temp_array[i], '=') - temp_array[i];
	return (name_len);
}
