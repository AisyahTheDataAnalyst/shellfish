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

# Directories of Token 
SRC_TOKEN = token
SRC_AST = ast
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I$(INC_DIR) 

# Directories of Execution
SRC_EXEC = execution
SRC_AST_EXEC = ast_execution
SRC_PIPE = pipe
SRC_RD = redirection
SRC_WD = word
SRC_BI = built_in
SRC_CMD = command
SRC_UTILS = utils

# Compiler & flags
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -rf

# Source files
SRC = $(addprefix $(SRC_DIR)/, \
		minishell.c \
		$(addprefix $(SRC_AST)/, \
		ast_parse.c \
		ast_utils.c) \
		$(addprefix $(SRC_TOKEN)/, \
		array_word.c \
		check_input.c \
		normalize_input.c \
		quote_check.c \
		replace_space.c \
		token_pipe.c \
		token_red.c \
		token_utils.c \
		token_utils2.c \
		token_word.c \
		tokenization.c) \
		$(addprefix $(SRC_EXEC)/, \
		$(SRC_AST_EXEC)/$(SRC_PIPE)/ast_pipe.c \
		$(SRC_AST_EXEC)/$(SRC_RD)/ast_redirection.c \
		$(SRC_AST_EXEC)/$(SRC_RD)/rd_heredoc.c \
		$(SRC_AST_EXEC)/$(SRC_RD)/rd_others.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_cd.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_echo.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_env.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_exit.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_export_add.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_export_only.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_export.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_pwd.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_unset.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_BI)/built_ins.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_CMD)/ast_word.c \
		$(SRC_AST_EXEC)/$(SRC_WD)/$(SRC_CMD)/word_utils.c \
		$(SRC_AST_EXEC)/ast_execution.c \
		$(SRC_UTILS)/free.c \
		$(SRC_UTILS)/init.c \
		$(SRC_UTILS)/reset_signal.c \
		$(SRC_UTILS)/signals.c))

#$(wildcard $(SRC_DIR)/token/*.c)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build rules
all: $(LIBFT) $(NAME)

$(LIBFT): FORCE
	@echo "$(PINK)$(BOLD)=======================================$(RESET)"
	@echo "$(CYAN)  🚀 Building libft...$(RESET)"
	@echo "$(PINK)$(BOLD)=======================================$(RESET)"
	@make bonus -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "$(YELLOW)Compiled ✅ $(GREEN) $(BOLD) $< $(RESET)"

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline
	@echo "$(GREEN)$(BOLD)✅ Build Successful: $(NAME)$(RESET)"

# Build library folder
$(OBJ_DIR): FORCE
	@mkdir -p $(OBJ_DIR)

# Clean object files and executable
clean:
	@echo "$(RED)❌ Deleting\t$(RESET)$(WHITE)Objects$(RESET)\t$(OBJ_DIR)";
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
#@echo "SRC: $(SRC)"
#@echo "OBJ: $(OBJ)"
#@echo "OBJ_DIR: $(OBJ_DIR)"

FORCE:

.PHONY: bonus all clean fclean re

# -I(include directory) - Tells the compiler to look for header files 
# -L(directory) - Tells the compiler to look for .a library path in this folder
# -l(%.a) - Tells the compiler to look for that specified .a file
