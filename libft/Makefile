# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2021/06/13 14:51:48 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

INCDIR	=	./libft

SRCDIR	=	./

SRCNAME	=	ft_strncmp.c \
			ft_strncpy.c \
			ft_strlen.c \
			ft_malloc_p.c


SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJS	=	$(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS)	-I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar	rcs	$(NAME)	$(OBJS)

all:		$(NAME)


clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
