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

static int	init_tokens(t_data *data, t_input_info *b_token, char *input)
{
	if (!input)
		exit(1);
	init_data(b_token, data);
	b_token->input = ft_strdup(input);
	free(input);
	if (!quote_check(b_token))
		return (0);
	if (!normalize_input(b_token))
		return (0);
	b_token->split_array = ft_split(b_token->input, ' ');
	if (!b_token->split_array)
		return (0);
	if (!check_input(b_token->split_array))
		return (0);
	create_token(b_token);
	if (!b_token->token)
		return (0);
	data->token = b_token->token;
	return (1);
}

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

void free_token_list(t_token *head)
{
    t_token *temp;
    int i;

    while (head)
    {
        temp = head->next;

        // Free the basin_buff content (array of strings)
        if (head->basin_buff)
        {
            for (i = 0; head->basin_buff[i]; i++)
                free(head->basin_buff[i]);
            free(head->basin_buff);
        }

        // Free the token node itself
        free(head);

        head = temp;
    }
}

static void print_ast(t_ast *node, int depth, char side)
{
    const char *arr[] = {
        "WORD",
        "HEREDOC",
        "APPEND",
        "REDIR_IN",
        "REDIR_OUT",
        "PIPE",
        NULL
    };

    if (!node) return;
    for (int i = 0; i < depth; i++) printf(CYAN"|  "COLOR);
    printf("%c[%s:%d]\n", side, arr[node->token->token_type], node->token->index);
    print_ast(node->left, depth + 1, 'L');
    print_ast(node->right, depth + 1, 'R');
}

int main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)env;
	char		*input;
	t_input_info	b_input;
	t_data		data;

	if (argc == 1)
	{
		while (1)
		{
			input = readline("$minishell: ");
			if (!init_tokens(&data, &b_input, input))
			{
				// Free token, array, input
				continue ;
			}
			if (data.token)
				print_tokens(data.token);
			else
				printf("Error creating tokens\n");
			if (!init_ast(&data))
			{
				// Free token, input
				continue ;
			}
			if (data.root)
			{
				printf("\n===========TREE=============\n");
    			print_ast(data.root, 0, 'T');
    			printf("\n===========TREE=============\n");
			}
			else
				printf("Error creating tree!\n");
			
		}
		ft_putstr_fd("No such files or directory", 2);
	}
	return (0);
}

// 	OLD INT MAIN
		// 	init_data(&data);
		// 	input = readline("$minishell: ");
		// 	printf("You entered %s\n", input);
		// 	if (!input)
		// 		exit(1);
		// 	if (!quote_check(input))
		// 	{
		// 		free(input);
		// 		continue;
		// 	}
		// 	printf("Spaced input: ");
		// 	for (int i = 0; input[i]; i++)
		// 	{
		// 		if (input[i] == 31)
		// 			printf("[SPACE]");
		// 		else
		// 			printf("%c", input[i]);
		// 	}
		// 	printf("\n");
		// 	input = normalize_input(input);
		// 	if (!input)
		// 		continue;
		// 	printf("Cleaned: %s\n", input);
		// 	data.split_array = ft_split(input, ' ');
		// 	if (!data.split_array)
		// 	{
		// 		printf("Fatal error: Array split failed");
		// 		free_arr(data.split_array);
		// 		exit (1);
		// 	}
		// 	int i = 0;
		// 	while (data.split_array[i])
		// 	{
		// 		printf("Basin[%d]: %s\n", i, data.split_array[i]);
		// 		i++;
		// 	}
		// 	printf("Basin[%d] = %s\n", i, data.split_array[i] ? data.split_array[i] : "NULL");
		// 	i = 0;
		// 	free(input);
		// 	if (!check_input(data.split_array))
		// 	{
		// 		free_arr(data.split_array);
		// 		continue;
		// 	}
		// 	create_token(&data, data.split_array);
		// 	printf("\n=== Token Linked List ===\n");
		// 	print_tokens(data.token);
		// 	// if (!init_ast(&data))
		// 	// {
		// 	// 	printf("Error - Tree creation failed");
		// 	// 	if (data.token)
		// 	// 	{
		// 	   // 		free_token_list(data.token);
		// 	// 		data.token = NULL;
		// 	// 	}
		// 	// 	free_arr(basin);
		// 	// 	continue;
		// 	// }
		// 	if (data.token)
		// 	{
		// 		   free_token_list(data.token);
		// 		data.token = NULL;
		// 	}
		// 	free_arr(data.split_array);
		// }
