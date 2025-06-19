/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:15:38 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:21:37 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			rd_out(t_token *token);
static int	multiple_outfiles(t_token *token);

// 0666 - mode = set permissions for a file only when you use O_CREAT
// 0666 - 0(owner)(group)(others)
// owner = you, creator of the file
// group = ex: colleagues working on the same project/ freinds in same club
// others = everyone else not related to owner and group
// just like how you share file through google docs/sheets (permissions)
// 0 at the front (optional) because all permissions bits witten in OCTAL
//	 (base-8), not base-10
// each digit : r(4) + w(2) + x(1)
// conclusion : 0, owner(r&w), group(r), others(x)
// conclusion : rw-r--r--
//
// TRUNC - truncate (empty) the file if it exist 
//
int	rd_out(t_token *token)
{
	int	final_outfile;

	final_outfile = multiple_outfiles(token);
	if (final_outfile == -1)
	{
		// dup2(final_outfile, STDOUT_FILENO);
		close(final_outfile);
		return (-1);
	}
	return (final_outfile);
}

// close(fd) = close previous file
static int	multiple_outfiles(t_token *token)
{
	int	fd;
	int	temp_fd;

	fd = -1;
	while (token && token->token_type == TOKEN_REDIRECT_IN)
	{
		temp_fd = open(token->basin_buff[0], O_RDWR | O_CREAT | O_TRUNC, 666);
		if (temp_fd == -1)
		{
			perror(token->basin_buff[0]);
			return (-1);
		}
		if (fd != -1)
			close (fd);
		fd = temp_fd;
		token = token->next;
	}
	return (fd);
}

// void	rd_out(t_token *token)
// {
// 	t_token	*curr;
// 	int		fd1;
// 	int		fd2;

// 	curr = token;
// 	curr = curr->next;
// 	fd1 = open(token->basin_buff[0], O_RDWR | O_CREAT | O_TRUNC, 666);
// 	while (1)
// 	{
// 		if (curr->token_type == TOKEN_REDIRECT_OUT)
// 		{
// 			fd2 = open(curr->basin_buff[0], O_RDWR | O_CREAT | O_TRUNC, 666);
// 			if (fd2 != -1)
// 			{
// 				close (fd1);
// 				token = curr->next;
// 				curr = token->next;
// 			}
// 		}
// 		else
// 			return ;
// 		if (token->token_type == TOKEN_REDIRECT_OUT)
// 		{
// 			fd1 = open(token->basin_buff[0], O_RDWR | O_CREAT | O_TRUNC, 666);
// 			if (fd1 != -1)
// 				close (fd2);
// 		}
// 		else
// 			return ;
// 	}
// }