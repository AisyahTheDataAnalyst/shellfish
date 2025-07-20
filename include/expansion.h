#ifndef EXPANSION_H
# define EXPANSION_H

#include <stdbool.h>

#define DQ '"'
#define SQ '\''

typedef enum quote_type
{
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
	NO_QUOTE,
}			t_quote_type;

typedef struct s_expansion
{
	t_quote_type 	type;
	int				in_quote;
}				t_expansion;

void expand_tokens(t_token *token, char **env);

#endif