/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/10 09:03:28 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// 1024 = enough for most directory path in typical use cases 
// the same number for get_next_line bonus
// can use PATH_MAX ([4096]) by <limits.h> 
// but need to be freed
void	bi_pwd(t_exc *exc)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("getcwd");
	exc->exit_code = 0;
}
