# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 15:32:32 by yelu              #+#    #+#              #
#    Updated: 2025/04/02 14:48:40 by yelu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAR_LINE = $(shell tput el)
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
RESET	=	\033[0m

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRC:.c=.o)
OBJSB = $(BONUS:.c=.o)

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

%.o : %.c #Pattern rule for any c file, create o file#
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@printf "$(YELLOW)Compiling\t%-33.33s\r$(RESET)" $@

$(NAME): $(OBJS) 
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CLEAR_LINE)"
	@echo "$(YELLOW)Compiled ✅ $(GREEN)$(BOLD)$(NAME)$(RESET)"

bonus: $(OBJSB)
	@$(AR) $(NAME) $(OBJSB)

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJSB)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	bonus all clean fclean re