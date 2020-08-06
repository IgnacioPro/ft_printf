# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/26 18:20:38 by IgnacioHB         #+#    #+#              #
#    Updated: 2020/08/05 13:08:46 by IgnacioHB        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS	= ft_intlen.c ft_formatter.c ft_display_d.c ft_printf.c ft_display_c.c ft_display_s.c ft_display_x.c ft_display_p.c ft_display_u.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -sC ./libft/
		cp libft/libft.a .
		mv libft.a $(NAME)
		ar rc  $(NAME) $(OBJS)
		ranlib $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		make -sC ./libft/ clean

fclean:	clean
		$(RM) $(NAME)
		make -sC ./libft/ fclean

re:		fclean all

.PHONY:	all fclean re