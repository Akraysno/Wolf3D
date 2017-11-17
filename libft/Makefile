# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 13:41:09 by gauffret          #+#    #+#              #
#    Updated: 2017/04/14 14:16:56 by gauffret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRC_PATH	=	src

OBJ_PATH	=	obj

SRC_NAME	=	brackets.c \
				ft_abs.c \
				ft_atoi.c ft_itoa.c ft_itoa_base.c ft_uitoa.c ft_uitoa_base.c \
				ft_intmaxtoa.c ft_intmaxtoa_base.c ft_uintmaxtoa.c \
				ft_uintmaxtoa_base.c \
				ft_ftoa.c \
				ft_bzero.c \
				ft_concat.c \
				ft_double_dim.c \
				ft_isalnum.c ft_isalpha.c ft_islower.c ft_isupper.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_ishex.c\
				ft_less_begin.c \
				ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
				ft_lstnew.c \
				ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memdel.c ft_memmove.c ft_memset.c \
				ft_putchar.c ft_putchar_fd.c \
				ft_putendl.c ft_putendl_fd.c \
				ft_putnbr.c ft_putnbr_fd.c \
				ft_putnbrendl.c ft_putnbrendl_fd.c \
				ft_putstr.c ft_putstr_fd.c \
				ft_realloc_sub.c \
				ft_strcat.c ft_strlcat.c ft_strncat.c \
				ft_strchr.c ft_strrchr.c ft_strchri.c\
				ft_strclr.c \
				ft_strcmp.c ft_strncmp.c \
				ft_strcpy.c ft_strncpy.c \
				ft_strdel.c ft_strnew.c \
				ft_strdup.c \
				ft_strequ.c ft_strnequ.c \
				ft_striter.c ft_striteri.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_strmap.c ft_strmapi.c \
				ft_strnstr.c ft_strstr.c \
				ft_strsplit.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c ft_toupper.c ft_strtolower.c ft_strtoupper.c \
				get_next_line.c \

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH	=	includes

INCL		=	-I$(INC_PATH)

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

.PHONY : all, clean, fclean, re, norme

all :	$(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< $(INCL)

$(NAME) : $(OBJ)
	@ar rc $@ $^
	@ranlib $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re :	fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

