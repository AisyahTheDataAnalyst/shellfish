/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/15 13:12:45 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//1024 = enough for most directory path in typical use cases 
// can use PATH_MAX ([4096]) by <limits.h> 
// but need to be freed
void	bi_pwd(char **av, t_data *data)
{
	char	cwd[1024];

	(void)av;
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("getcwd");
	data->exit_code = 0;
}
