# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 12:24:26 by aimokhta          #+#    #+#              #
#    Updated: 2025/07/17 15:03:22 by yelu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
PINK 	=	\033[35m
RESET	=	\033[0m

NAME =	libft.a

SRC	=	ft_array_size.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_split.c \
		ft_split_squote.c \
		ft_freewords.c \
		ft_wordcount.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		get_next_line_utils.c \
		
SRC_B =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= cc -g3 #-O0 -fsanitize=address
FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIBC) $(NAME) $(OBJ)
	@echo "$(CLEAR_LINE)"

%.o: %.c
	@$(CC) $(FLAG) -c $< -o $@
	@printf "$(YELLOW)Compiling\t%-33.33s\r$(RESET)" $@
# $@ (the target), $< (the first prerequisite).
# Stick to $() unless theres a specific reason to use ${}. It works in most cases without issues.
# Use ${} only if you’re combining variables with text directly (ex: echo ${VAR}world ) || referencing shell-specific variables like (ex: echo ${PATH}) or ${HOME}

bonus: $(NAME) $(OBJ_B)
	@$(LIBC) $(NAME) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_B)
	$(RM) libft.h.gch

re: fclean all

.PHONY: all bonus clean fclean re