/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:57:34 by yelu              #+#    #+#             */
/*   Updated: 2025/05/02 21:15:15 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"
#include "../include/ast.h"
#include "../include/minishell.h"

// static void print_ast(t_ast *node, int depth, char side)
// {
//     const char *arr[] = {
//         "WORD",
//         "HEREDOC",
//         "APPEND",
//         "REDIR_IN",
//         "REDIR_OUT",
//         "PIPE",
//         NULL
//     };

//     if (!node) return;
//     for (int i = 0; i < depth; i++) printf(CYAN"|  "COLOR);
//     printf("%c[%s:%d]\n", side, arr[node->token->token_type], node->token->index);
//     print_ast(node->left, depth + 1, 'L');
//     print_ast(node->right, depth + 1, 'R');
// }

static void print_tokens(t_token *head)
{
    const char *arr[7] = {
        "WORD",
        "HEREDOC",
        "APPEND",
        "REDIR_IN",
        "REDIR_OUT",
        "PIPE",
        NULL
    };

    printf("\n=== Token Linked List ===\n");
    while (head)
    {
        printf("Token index: %d\n", head->index);
        printf("Token type: %s\n", arr[head->token_type]);
        if (head->basin_buff)
        {
            printf("Token basin_buff content:\n");
            for (int i = 0; head->basin_buff[i]; i++)
                printf("  - %s\n", head->basin_buff[i]);
        }
        else
            printf("Token basin_buff is NULL\n");
        printf("---------------------------\n");
        head = head->next;
    }
    printf("=== END OF LINKED LIST ===\n");
}

int main(int argc, char **argv, char **env)
{
	(void)argv;
	//(void)env;
	char		*input;
	t_input_info	b_input;
	t_data		data;

	if (argc == 1)
	{
		while (1)
		{
			input = readline("$minishell: ");
			if (!init_tokens(&data, &b_input, input))
				continue ;
			print_tokens(data.token);
			expand_tokens(data.token, env);
			printf("\033[1;32m\nAFTER EXPANSION\n\033[0m");
			print_tokens(data.token);
			if (!init_ast(&data))
				continue ;
			if (data.token)
				free_token_list(&data);
			if (data.root)
				free_ast(&data);
			continue ;
		}
		ft_putstr_fd("No such files or directory", 2);
	}
	return (0);
}
