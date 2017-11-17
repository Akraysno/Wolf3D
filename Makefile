# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 11:59:15 by gauffret          #+#    #+#              #
#    Updated: 2017/02/02 11:59:18 by gauffret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	wolf3d

SRC_PATH	=	src

OBJ_PATH	=	obj

SRC_NAME	=	main.c \
				mouse.c \
				run_quit.c \
				keyboard.c \
				repeat_key.c \
				draw.c \
				draw2.c \
				draw3.c \
				img.c \
				init.c \
				check_file.c \
				verif_map.c \
				error_map.c \
				suppr_img.c \

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH	=	includes

CC			=	clang

CFLAGS		=	-Ofast -Wall -Werror -Wextra

CPPFLAGS	=	-I$(INC_PATH)

LDFLAGS		=	-Llibft -L/usr/local/lib/

LDLIBS		=	-lft

INCLUDE		=	-I/usr/local/include -I$(INC_PATH)

BONUS		=	-lpthread

.PHONY : all, clean, fclean, re, norme, start, runall

all :	$(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< $(INCLUDE)
	
$(NAME) :	start $(OBJ)
	@echo "  \033[38;5;202m│\033[0m   Objects Wolf3D   : \033[38;5;2mDone\033[0m        \033[38;5;202m│\033[0m"
	@echo "\033[38;5;202m  ├──────────────────────────────────┤\033[0m"
	@echo "  \033[38;5;202m│\033[0m   wolf3d           : \033[38;5;3mStart\033[0m       \033[38;5;202m│\033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@ -lm -lmlx -framework OpenGL -framework AppKit $(BONUS)
	@echo "  \033[38;5;202m│\033[0m   wolf3d           : \033[38;5;2mDone\033[0m        \033[38;5;202m│\033[0m"
	@echo "\033[38;5;202m  └──────────────────────────────────┘\033[0m"

clean:
	@echo ""
	@echo "\033[38;5;202m  ┌────────── DELETE FILES ──────────┐\033[0m"
	@echo "  \033[38;5;202m│\033[0m    Objects Libft   :\c"
	@make -C libft/ clean
	@echo " \033[38;5;1mDeleted\033[0m     \033[38;5;202m│\033[0m"
	@echo "  \033[38;5;202m│\033[0m    Objects Wolf3D  :\c"
	@rm -rf $(OBJ)
	@echo " \033[38;5;1mDeleted\033[0m     \033[38;5;202m│\033[0m"
	@echo "\033[38;5;202m  +──────────────────────────────────+\033[0m"

fclean: clean
	@echo "  \033[38;5;202m│\033[0m    libft.a         :\c"
	@make -C libft/ fclean
	@echo " \033[38;5;1mDeleted\033[0m     \033[38;5;202m│\033[0m"
	@echo "  \033[38;5;202m│\033[0m    wolf3d          :\c"
	@rm -rf $(NAME)
	@echo " \033[38;5;1mDeleted\033[0m     \033[38;5;202m│\033[0m"
	@echo "\033[38;5;202m  └──────────────────────────────────┘\033[0m"

re :	fclean all

norme:
	make -C libft/ norme
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

start:
	@echo ""
	@echo "\033[38;5;202m  ┌────────── COMPILATION ───────────┐\033[0m"
	@echo "  \033[38;5;202m│\033[0m   Libft            : \033[38;5;3mStart\033[0m       \033[38;5;202m│\033[0m"
	@make -C libft/
	@echo "  \033[38;5;202m│\033[0m   libft            : \033[38;5;2mDone\033[0m        \033[38;5;202m│\033[0m"
	@echo "\033[38;5;202m  ├──────────────────────────────────┤\033[0m"
	@echo "  \033[38;5;202m│\033[0m   Objects RT_v1    : \033[38;5;3mStart\033[0m       \033[38;5;202m│\033[0m"

runall: re
	./fractol &
	./fractol fwf &
	./fractol Mandelbrot &
	./fractol Julia &
	./fractol Mandelbar &
	./fractol Cross &
	./fractol Bow &
	./fractol Burningship &