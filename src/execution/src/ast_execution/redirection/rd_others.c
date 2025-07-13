/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:16:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/13 16:36:13 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// it dosent work if i put ast_execution(ast->left, exc) at the top
void	rd_out(t_ast *ast, t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(ast->token->basin_buff[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (temp_fd == -1)
	{
		printf("Failed to open %s for redirection out\n", \
ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	printf("temp_fd: %d\n", temp_fd);
	printf("opened %s\n", ast->token->basin_buff[0]);
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
		printf("Failed to open %s for redirection in\n", \
ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	printf("temp_fd: %d\n", temp_fd);
	printf("opened %s\n", ast->token->basin_buff[0]);
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
		printf("Failed to open %s for redirection append\n", \
ast->token->basin_buff[0]);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	printf("temp_fd: %d\n", temp_fd);
	printf("opened %s\n", ast->token->basin_buff[0]);
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	ast_execution(ast->left, exc);
}

int	reset_cursor_heredocfd(int heredoc_fd, t_exc *exc)
{
	heredoc_fd = open("heredoc_fd", O_RDONLY);
	if (heredoc_fd == -1)
	{
		printf("Failed to open heredoc_fd for reading as a infile\n");
		exc->exit_code = PERMISSION_DENIED;
		return (-1);
	}
	return (heredoc_fd);
}

//restoring by dupped_ to put back the original stdout/stdin for readline
// void	rd_append(t_ast *ast, t_exc *exc)
// {
// 	int	temp_fd;
// 	int	dupped_stdout;

// 	// if (ast->left)
// 	// 	ast_execution(ast->left, exc);
// 	temp_fd = open(ast->token->basin_buff[0], O_RDWR | O_CREAT \
// | O_APPEND, 0666);
// 	if (temp_fd == -1)
// 	{
// 		printf("Failed to open %s for redirection append\n", \
// ast->token->basin_buff[0]);
// 		return ;
// 	}
// 	// if (exc->process->outfile != -1)
// 	// 	close(exc->process->outfile);
// 	// exc->process->outfile = temp_fd;
// 	dupped_stdout = dup(STDOUT_FILENO);
// 	// dup2(exc->process->outfile, STDOUT_FILENO);
// 	// close(exc->process->outfile);
// 	dup2(temp_fd, STDOUT_FILENO);
// 	close(temp_fd);
// 	ast_execution(ast->left, exc);
// 	dup2(dupped_stdout, STDOUT_FILENO);
// 	close(dupped_stdout);
// }

// void	rd_in(t_ast *ast, t_exc *exc)
// {
// 	int	temp_fd;
// 	int	dupped_stdin;

// 	// if (ast->left)
// 	// 	ast_execution(ast->left, exc);
// 	temp_fd = open(ast->token->basin_buff[0], O_RDONLY);
// 	if (temp_fd == -1)
// 	{
// 		printf("Failed to open %s for redirection in\n", \
// ast->token->basin_buff[0]);
// 		return ;
// 	}
// 	// if (exc->process->infile != -1)
// 	// 	close(exc->process->infile);
// 	// exc->process->infile = temp_fd;
// 	dupped_stdin = dup(STDIN_FILENO);
// 	// dup2(exc->process->infile, STDIN_FILENO);
// 	// close(exc->process->infile);
// 	dup2(temp_fd, STDIN_FILENO);
// 	close(temp_fd);
// 	ast_execution(ast->left, exc);
// 	dup2(dupped_stdin, STDIN_FILENO);
// 	close(dupped_stdin);
// }

//it dosent work if i put ast_execution(ast->left, exc) at the top
// void	rd_out(t_ast *ast, t_exc *exc)
// {
// 	int	temp_fd;
// 	int	dupped_stdout;

// 	temp_fd = open(ast->token->basin_buff[0], O_RDWR | O_CREAT | O_TRUNC, 0666);
// 	if (temp_fd == -1)
// 	{
// 		printf("Failed to open %s for redirection out\n", \
// ast->token->basin_buff[0]);
// 		return ;
// 	}
// 	printf("opened %s\n", ast->token->basin_buff[0]);
// 	if (exc->process->outfile != -1)
// 		close(exc->process->outfile);
// 	exc->process->outfile = temp_fd;
// 	dupped_stdout = dup(STDOUT_FILENO);
// 	dup2(exc->process->outfile, STDOUT_FILENO);
// 	close(exc->process->outfile);
// 	ast_execution(ast->left, exc);
// 	dup2(dupped_stdout, STDOUT_FILENO);
// 	close(dupped_stdout);
// }


