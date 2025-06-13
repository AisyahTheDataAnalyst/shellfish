# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 18:51:17 by yelu              #+#    #+#              #
#    Updated: 2025/04/28 18:51:17 by yelu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc minishell.c -lreadline <-- must use this flag when compiling to use readline library

# Colors
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
PINK 	=	\033[35m
RESET	=	\033[0m

# Program name
NAME = minishell

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I$(INC_DIR) -I$(LIBFT_DIR)

# Compiler & flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

# Source files
SRC = $(addprefix $(SRC_DIR)/, minishell.c normalize_input.c token_utils.c) 
#$(wildcard $(SRC_DIR)/token/*.c)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build rules
all: $(LIBFT) $(NAME)

$(LIBFT): FORCE
	@echo "$(PINK)$(BOLD)=======================================$(RESET)"
	@echo "$(CYAN)  🚀 Building libft...$(RESET)"
	@echo "$(PINK)$(BOLD)=======================================$(RESET)"
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -I/usr/include -lreadline -O3 -c $< -o $@
	@echo "$(YELLOW)Compiled ✅ $(GREEN) $(BOLD) $< $(RESET)"

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -lreadline
	@echo "$(GREEN)$(BOLD)✅ Build Successful: $(NAME)$(RESET)"

# Build library folder
$(OBJ_DIR): FORCE
	@mkdir -p $(OBJ_DIR)

# Clean object files and executable
clean:
	@echo "$(RED)❌ Deleting\t$(RESET)$(WHITE)Objects$(RESET)\t$(OBJB_DIR)";
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)✅ Removed\t$(RESET)$(WHITE)Objects$(RESET)"

fclean: clean
	@echo "$(RED)❌ Deleting libraries$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)❌ Deleting$(RESET)\t$(NAME)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✅ Removed\t$(RESET)$(WHITE)$(NAME)$(RESET)"

re: fclean all

# # debug:
# @echo "SRC: $(SRC)"
# @echo "OBJ: $(OBJ)"
# @echo "OBJ_DIR: $(OBJ_DIR)"

FORCE:

.PHONY: bonus all clean fclean re

# -I(include directory) - Tells the compiler to look for header files 
# -L(directory) - Tells the compiler to look for .a library path in this folder
# -l(%.a) - Tells the compiler to look for that specified .a file
