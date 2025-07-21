#ifndef EXPANSION_H
# define EXPANSION_H

#include <stdbool.h>
#include "execution.h"

typedef struct s_exc	t_exc;

void expand_tokens(t_token *token, t_exc *exc);

#endif