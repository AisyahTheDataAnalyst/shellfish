/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:16:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/24 13:05:27 by aimokhta         ###   ########.fr       */
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
		if (exc->process->infile != exc->process->heredoc_fd[READ])
			close(exc->process->infile);
	exc->process->infile = temp_fd;
	execution(ast->left, exc);
}

void	rd_heredoc(t_ast *ast, t_exc *exc)
{
	if (exc->process->infile != -1)
		if (exc->process->infile != exc->process->heredoc_fd[READ])
			close(exc->process->infile);
	exc->process->infile = exc->process->heredoc_fd[READ];
	execution(ast->left, exc);
}
