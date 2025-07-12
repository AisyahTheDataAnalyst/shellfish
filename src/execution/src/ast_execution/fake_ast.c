/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:14:40 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/12 14:13:23 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// void	ft_lstadd_left(t_ast **root, t_ast *new)
// {
// 	t_list	*last;

// 	if (!root || !new)
// 		return ;
// 	if (!*root)
// 	{
// 		*root = new;
// 		return ;
// 	}
// 	last = ft_lstlast_left(*root);
// 	last->next = new;
// }

// t_list	*ft_lstlast_left(t_ast *root)
// {
// 	if (!root)
// 		return (NULL);
// 	while (root->left != NULL)
// 		root = root->left;
// 	return (root);
// }

// t_list	*ft_lstlast_right(t_ast *root)
// {
// 	if (!root)
// 		return (NULL);
// 	while (root->right != NULL)
// 		root = root->right;
// 	return (root);
// }

//can i forgive myself? i dont know if i can after making him so uncomfortable :(

// void	ft_lstnew_ast(t_exc *exc)
// {
// 	t_ast	*new_node;
// 	t_ast	*node_word;

// 	new_node = (t_ast *)malloc(sizeof(t_ast));
// 	if (!new_node)
// 		return ;
// 	node_word = (t_ast *)malloc(sizeof(t_ast));
// 	if (!node_word)
// 		return ;
// 	new_node->token = malloc(sizeof(t_token));
// 	if (!new_node->token)
// 		return ;
// 	node_word->token = malloc(sizeof(t_token));
// 	if (!node_word->token)
// 		return ;

// 	// Zero-initialize tokens
// 	ft_bzero(new_node->token, sizeof(t_token));
// 	ft_bzero(node_word->token, sizeof(t_token));

// 	new_node->token->token_type = TOKEN_REDIRECT_OUT;
// 	new_node->token->basin_buff = malloc(sizeof(char *) * 2);
// 	new_node->token->basin_buff[0] = ft_strdup("out1");
// 	new_node->token->basin_buff[1] = NULL;
// 	new_node->right = NULL;
// 	new_node->left = node_word;

// 	node_word->token->token_type = TOKEN_WORD;
// 	node_word->token->basin_buff = malloc(sizeof(char *) * 4);
// 	node_word->token->basin_buff[0] = ft_strdup("echo");
// 	node_word->token->basin_buff[1] = ft_strdup("hello");
// 	node_word->token->basin_buff[2] = ft_strdup("world");
// 	node_word->token->basin_buff[3] = NULL;
// 	node_word->right = NULL;
// 	node_word->left = NULL;

// 	exc->ast = new_node;
// }

t_ast *create_ast_node(char **args, t_type type)
{
	t_ast *node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->token = malloc(sizeof(t_token));
	if (!node->token)
		return (NULL);
	// ft_bzero(node, sizeof(t_ast));
	// ft_bzero(node->token, sizeof(t_token));

	node->token->token_type = type;

	// count args
	int count = 0;
	while (args && args[count])
		count++;

	node->token->basin_buff = malloc(sizeof(char *) * (count + 1));
	if (!node->token->basin_buff)
		return (NULL);

	for (int i = 0; i < count; i++)
		node->token->basin_buff[i] = ft_strdup(args[i]);
	node->token->basin_buff[count] = NULL;

	node->left = NULL;
	node->right = NULL;

	return node;
}

void insert_left_node(t_ast *parent, char **args, t_type type)
{
	if (!parent)
		return ;
	parent->left = create_ast_node(args, type);
}

void insert_right_node(t_ast *parent, char **args, t_type type)
{
	if (!parent)
		return ;
	parent->right = create_ast_node(args, type);
}

void	free_ast(t_ast *node)
{
	int i;

	if (!node)
		return;

	// Free left and right recursively
	free_ast(node->left);
	free_ast(node->right);

	// Free basin_buff (array of strings)
	if (node->token)
	{
		if (node->token->basin_buff)
		{
			i = 0;
			while (node->token->basin_buff[i])
			{
				free(node->token->basin_buff[i]);
				i++;
			}
			free(node->token->basin_buff);
		}
		free(node->token);
	}

	free(node);
}

