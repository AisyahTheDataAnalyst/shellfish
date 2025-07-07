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

static void free_token_list(t_token *head)
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

int main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)env;
	char		*input;
	t_data		data;

	init_data(&data);
	if (argc == 1)
	{
		while (1)
		{
			init_data(&data);
			input = readline("$minishell: ");
			printf("You entered %s\n", input);
			if (!input)
				exit(1);
			if (!quote_check(input))
			{
				free(input);
				continue;
			}
			printf("Spaced input: ");
			for (int i = 0; input[i]; i++)
			{
				if (input[i] == 31)
					printf("[SPACE]");
				else
					printf("%c", input[i]);
			}
			printf("\n");
			input = normalize_input(input);
			if (!input)
				continue;
			printf("Cleaned: %s\n", input);
			data.split_array = ft_split(input, ' ');
			if (!data.split_array)
			{
				printf("Fatal error: Array split failed");
				free_arr(data.split_array);
				exit (1);
			}
			int i = 0;
			while (data.split_array[i])
			{
				printf("Basin[%d]: %s\n", i, data.split_array[i]);
				i++;
			}
			printf("Basin[%d] = %s\n", i, data.split_array[i] ? data.split_array[i] : "NULL");
			i = 0;
			free(input);
			if (!check_input(data.split_array))
			{
				free_arr(data.split_array);
				continue;
			}
			init_token(&data, data.split_array);
			printf("\n=== Token Linked List ===\n");
			print_tokens(data.token);
			// if (!init_ast(&data))
			// {
			// 	printf("Error - Tree creation failed");
			// 	if (data.token)
			// 	{
			   // 		free_token_list(data.token);
			// 		data.token = NULL;
			// 	}
			// 	free_arr(basin);
			// 	continue;
			// }
			if (data.token)
			{
				   free_token_list(data.token);
				data.token = NULL;
			}
			free_arr(data.split_array);
		}
		ft_putstr_fd("No such files or directory", 2);
	}
	return (0);
}
