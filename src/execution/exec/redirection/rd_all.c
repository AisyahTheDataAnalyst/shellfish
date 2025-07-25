/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:16:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/25 15:29:12 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// it dosent work if i put execution(ast->left, exc) at the top
void	rd_out(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_WRONLY | O_CREAT \
| O_TRUNC, 0644);
	if (temp_fd == -1)
	{
		ft_putstr_fd("shellfish: ", 2);
		perror(ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	execution(ast->left, exc);
}

void	rd_append(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_WRONLY | O_CREAT | \
O_APPEND, 0644);
	if (temp_fd == -1)
	{
		ft_putstr_fd("shellfish: ", 2);
		perror(ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	execution(ast->left, exc);
}

void	rd_in(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_RDONLY);
	if (temp_fd == -1)
	{
		ft_putstr_fd("shellfish: ", 2);
		perror(ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	if (exc->process->infile != -1)
		if (exc->process->infile != exc->process->heredoc_fd)
			close(exc->process->infile);
	exc->process->infile = temp_fd;
	execution(ast->left, exc);
}

void	rd_heredoc(t_ast *ast, t_exc *exc)
{
	if (exc->process->reset_cursor_hd == false)
	{
		exc->process->heredoc_fd = reset_cursor_heredocfd(exc);
		exc->process->reset_cursor_hd = true;
	}
	if (exc->process->infile != -1 && \
exc->process->infile != exc->process->heredoc_fd)
		close(exc->process->infile);
	exc->process->infile = exc->process->heredoc_fd;
	execution(ast->left, exc);
}

int	reset_cursor_heredocfd(t_exc *exc)
{
	exc->process->heredoc_fd = open("heredoc_fd", O_RDONLY);
	if (exc->process->heredoc_fd == -1)
	{
		ft_putstr_fd("shellfish: ", 2);
		perror("heredoc_fd");
		exc->exit_code = PERMISSION_DENIED;
		return (-1);
	}
	return (exc->process->heredoc_fd);
}
