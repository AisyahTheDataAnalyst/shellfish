# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 13:45:31 by aimokhta          #+#    #+#              #
#    Updated: 2025/07/13 08:33:26 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execution

CC = cc

#compilation flags
CFLAGS = -Wall -Wextra -Werror -O0 -g3 #-fsanitize=address \
-fsanitize-recover=leak 
#valgrind --leak-check=full --show-leak-kinds=all ./execution - 204215 bytes in 21 blocks

#linker flag
LFLAGS = -lreadline

# directory that contains source files
SRC_MAIN = src
SRC_EXEC_DIR = execution
SRC_AST = ast_execution
SRC_PIPE = pipe
SRC_RD = redirection
SRC_WD = word
SRC_BI = built_in
SRC_CMD = command
SRC_UTILS = utils

SRC =	\
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_PIPE)/ast_pipe.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_RD)/ast_redirection.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_RD)/rd_heredoc.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_RD)/rd_others.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_cd.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_echo.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_env.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_exit.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_export_add.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_export_only.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_export.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_pwd.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/bi_unset.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_BI)/built_ins.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_CMD)/ast_word.c \
		$(SRC_MAIN)/$(SRC_AST)/$(SRC_WD)/$(SRC_CMD)/word_utils.c \
		$(SRC_MAIN)/$(SRC_AST)/ast_execution.c \
		$(SRC_MAIN)/$(SRC_AST)/fake_ast.c \
		$(SRC_MAIN)/$(SRC_UTILS)/free.c \
		$(SRC_MAIN)/$(SRC_UTILS)/init.c \
		$(SRC_MAIN)/$(SRC_UTILS)/reset_signal.c \
		$(SRC_MAIN)/$(SRC_UTILS)/signals.c \
		$(SRC_MAIN)/main.c
	
INC = -I include -I libft
# this is what is caused to not write explicit path for all #includes in all header and c files
# -I means it will search the header in that directory that is mentioned in the each file's #include

OBJ_FOLDER = obj_files

# patsubst : pattern substitution function
# create a list of .o files in the object folder
OBJ_SRC = $(patsubst %.c, $(OBJ_FOLDER)/%.o, $(SRC))

LIBFT_DIR = libft/libft.a

# color
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m  	#white

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	@make bonus -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ_SRC) $(LIBFT_DIR) $(LFLAGS) -o $(NAME)
	@echo "${GREEN}----------COMPILED DONE----------\n${RESET}"

$(OBJ_FOLDER)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
# add $(INC) to not do explicit path to all #include of all header and c files

clean:
	@rm -rf $(OBJ_FOLDER)
	@make fclean -C libft
	@rm -f libft.a
	@echo "${GREEN}----------CLEANED----------\n${RESET}"

fclean : clean
	rm -f $(NAME)
	@echo "${GREEN}----------FULLY REMOVE----------\n${RESET}"

re : fclean all

.PHONY : all clean fclean re