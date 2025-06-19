/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:19:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:14:37 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_export(char **av, t_data *data)
{
	if (ft_strncmp(av[0], "export", 6) == 0 && ft_strchr(av[1], '='))
	{
		data->exit_code = 0;
		export_add(av, data);
	}
	else if (ft_strncmp(av[0], "export", 6) == 0 && !av[1])
	{
		export_only(data->exec);
		data->exit_code = 0;
	}
}
