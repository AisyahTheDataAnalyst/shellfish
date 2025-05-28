/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:05:37 by yelu              #+#    #+#             */
/*   Updated: 2025/05/21 18:05:37 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_type check_token_type(char *basin)
{
	if (ft_strncmp(basin, "|", 2) == 0)
		return (TOKEN_PIPE);
	else if (ft_strncmp(basin, "<", 2) == 0)
		return (TOKEN_REDIRECT_IN);
	else if (ft_strncmp(basin, ">", 2) == 0)
		return (TOKEN_REDIRECT_OUT);
	else if (ft_strncmp(basin, ">>", 3) == 0)
		return (TOKEN_APPEND);
	else if (ft_strncmp(basin, "<<", 3) == 0)
		return (TOKEN_HEREDOC);
	else
		return (TOKEN_WORD);
}

void    init_token(char **basin)
{
    int type;
    int i;

    i = 0;
    while(basin[i])
    {
        type = check_token_type(basin[i]);
		assign_token(type);
        i++;
    }
}

void	assign_token(int type, t_token *data)
{
	if (type == TOKEN_WORD)
	{
		if (!data->basin_buff)
			new_token(data);
		else
		{
			
		}
	}
}

void	new_token(t_token *data)
{

}