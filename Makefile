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
INC = -I$(INC_DIR)

# Directories of Token & AST
SRC_TOKEN = token
SRC_AST = ast

# Directories of Execution
SRC_EXECUTION = execution
SRC_EXEC = exec
SRC_PIPE = pipe
SRC_RD = redirection
SRC_WD = word
SRC_BI = built_in
SRC_CMD = command
SRC_UTILS = utils

#Directories of Expansion
SRC_EXPANSION = expansion

# Compiler & flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
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
		$(addprefix $(SRC_EXPANSION)/, \
		expansion.c \
		handle_quote.c \
		param_expansion.c \
		utils.c) \
		$(addprefix $(SRC_EXECUTION)/, \
		$(SRC_EXEC)/$(SRC_PIPE)/exec_pipe.c \
		$(SRC_EXEC)/$(SRC_RD)/exec_redirection.c \
		$(SRC_EXEC)/$(SRC_RD)/combine_all_heredoc.c \
		$(SRC_EXEC)/$(SRC_RD)/rd_all.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_cd.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_echo.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_env.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_exit.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_export_add.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_export_only.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_export.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_pwd.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/bi_unset.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_BI)/built_ins.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_CMD)/exec_word.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_CMD)/word_utils.c \
		$(SRC_EXEC)/$(SRC_WD)/$(SRC_CMD)/access_and_execve.c \
		$(SRC_EXEC)/execution.c \
		$(SRC_UTILS)/free.c \
		$(SRC_UTILS)/init.c \
		$(SRC_UTILS)/reset.c \
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
	@printf "$(YELLOW)Compiling\t%-33.33s\r $(GREEN) $(BOLD) $(RESET)" $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline
	@printf "$(YELLOW)Compiling\t%-33.33s\r $(GREEN) $(BOLD) $(RESET)" $@
	@echo "$(CLEAR_LINE)"
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
