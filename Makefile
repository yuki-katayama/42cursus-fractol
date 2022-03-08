# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:41:47 by kyuki             #+#    #+#              #
#    Updated: 2022/03/08 12:42:05 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	gcc

MLX	=		-Imlx

VALGRIND = valgrind

CFLAGS	=	-Wall -Werror -Wextra

SANFLAGS	=	-g -fsanitize=address

VALFLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666

MLXFLAGS	=	-lXext -lX11 -lm -lbsd

MLXPATH	=	./minilibx

LFPATH	=	./libft

SRCDIR  = ./srcs/

SRCNAME	=	fractol \
			hook \
			mandelbrot \
			julia \
			graphic \
			close

BSRCNAME =	fractol_bonus \
			hook_bonus \
			hook_key_bonus \
			hook_mouse_bonus \
			mandelbrot_bonus \
			julia_bonus \
			burningship_bonus \
			description_bonus \
			graphic \
			close

SRCS	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME)))

BSRCS	=	$(addsuffix .c, $(addprefix srcs/, $(BSRCNAME)))

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

.PHONY: all
all	:	$(NAME) ## Run compile

$(MLXPATH):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLXPATH)

$(NAME)	:	$(MLXPATH) ${OBJS}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C $(MLXPATH)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			$(CC) -g $(MLX) ${OBJS} $(MLXPATH)/libmlx.a $(LFPATH)/libft.a $(CFLAGS) $(MLXFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: san
san	:	${OBJS} ## Run sanitize
			@echo "\n\033[0;32mCompiling..."
			$(CC) -g $(MLX) ${OBJS} $(SANFLAGS) $(MLXPATH)/libmlx.a $(LFPATH)/libft.a $(CFLAGS) $(MLXFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: val
val	:	 ${OBJS} ## Run valgrind
			$(VALGRIND) $(VALFLAGS) ./fractol julia

.PHONY: clean
clean	:	## Remove object
			@echo "\033[0;33mCleaning..."
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			$(MAKE) clean -C ./minilibx
			$(MAKE) clean -C ./libft
			@echo "\033[0m"

.PHONY: fclean
fclean	:	clean ## Remove object and static
			@echo "\033[0;33mRemoving executable..."
			$(RM) -rf ./minilibx
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)
			@echo "\033[0m"

.PHONY: re
re	:	fclean all ## Retry cmpiles

.PHONY: bonus
bonus	:	$(MLXPATH) ${BOBJS} ## Run bonus compile
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C $(MLXPATH)
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			$(CC) -g $(MLX) ${BOBJS} $(MLXPATH)/libmlx.a $(LFPATH)/libft.a $(CFLAGS) $(MLXFLAGS) -o ${NAME}
#			$(MAKE) clean
			@echo "Complete\033[0m"

.PHONY: test1
test1	:	## Run Mandelbrot
			./fractol mandelbrot

.PHONY: test2
test2	:	## Run juliabrot
			./fractol julia

.PHONY: test3
test3	:	## Run burningship
			./fractol burningship

.PHONY: help
help	: ## Display this help
	@grep -E '^[a-zA-Z1-9_-]+	:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
