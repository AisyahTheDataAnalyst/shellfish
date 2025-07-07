# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 13:45:31 by aimokhta          #+#    #+#              #
#    Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execution

CC = cc

#compilation flags
CFLAGS = -Wall -Wextra -Werror -O0 -g3 -fsanitize=address \
			-fsanitize-recover=leak 
#valgrind --leak-check=full --show-leak-kinds=all ./execution - 204215 bytes in 21 blocks

#linker flag
LFLAGS = -lreadline

# directory that contains source files
#SRC = src
SRC_DIR_EXEC = execution
SRC_DIR_W = working
SRC_BI_DIR = built_in
SRC_UTILS_DIR = utils
#SRC_DIR_NW = not working
#SRC_RD_DIR = redirection
#SRC_PIPE_DIR = pipe
#SRC_WORD_DIR = word

SRC =	\
		$(SRC_BI_DIR)/bi_cd.c \
		$(SRC_BI_DIR)/bi_echo.c \
		$(SRC_BI_DIR)/bi_env.c \
		$(SRC_BI_DIR)/bi_exit.c \
		$(SRC_BI_DIR)/bi_export_add.c \
		$(SRC_BI_DIR)/bi_export_only.c \
		$(SRC_BI_DIR)/bi_export.c \
		$(SRC_BI_DIR)/bi_pwd.c \
		$(SRC_BI_DIR)/bi_unset.c \
		$(SRC_BI_DIR)/built_ins.c \
		$(SRC_UTILS_DIR)/free.c \
		$(SRC_UTILS_DIR)/init.c \
		$(SRC_UTILS_DIR)/reset_signal.c \
		$(SRC_UTILS_DIR)/signals.c \
		main.c
# 		$(SRC_DIR_NW)/$(SRC_PIPE_DIR)/ast_pipe.c \
		$(SRC_DIR_NW)/$(SRC_RD_DIR)/rd_check.c \
		$(SRC_DIR_NW)/$(SRC_RD_DIR)/rd_heredoc.c \
		$(SRC_DIR_NW)/$(SRC_RD_DIR)/rd_others.c \
		$(SRC_DIR_NW)/$(SRC_RD_DIR)/ast_redirection.c \
		$(SRC_DIR_NW)/$(SRC_WORD_DIR)/ast_word.c
	
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