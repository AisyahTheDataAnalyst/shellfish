/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:16:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/16 11:17:47 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// it dosent work if i put ast_execution(ast->left, exc) at the top
void	rd_out(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_WRONLY | O_CREAT \
| O_TRUNC, 0644);
	if (temp_fd == -1)
	{
		printf("shellfish: %s: Permission denied\n", \
ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	ast_execution(ast->left, exc);
}

void	rd_in(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_RDONLY);
	if (temp_fd == -1)
	{
		printf("shellfish: %s: Permission denied\n", \
ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	if (exc->process->infile != -1)
		close(exc->process->infile);
	exc->process->infile = temp_fd;
	ast_execution(ast->left, exc);
}

void	rd_append(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_WRONLY | O_CREAT \
| O_APPEND, 0644);
	if (temp_fd == -1)
	{
		printf("shellfish: %s: Permission denied\n", \
ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	ast_execution(ast->left, exc);
}

int	reset_cursor_heredocfd(int heredoc_fd, t_exc *exc)
{
	close(heredoc_fd);
	heredoc_fd = open("heredoc_fd", O_RDONLY);
	if (heredoc_fd == -1)
	{
		printf("shellfish: heredoc_fd: Permission denied\n");
		exc->exit_code = PERMISSION_DENIED;
		return (-1);
	}
	return (heredoc_fd);
}
