# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:42:04 by smazouz           #+#    #+#              #
#    Updated: 2022/01/19 21:19:07 by smazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM =	ft_read_map.c ft_strjoin.c ft_split.c ft_strlcpy.c ft_itoa.c ft_printf_map.c ft_strlen.c the_game.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_strdup.c \
		ft_check_map.c ft_check_characters.c ft_perser.c ft_check_map_.c ft_position.c ft_moves.c ft_ghrafique.c

SRCB = $(SRCM:.c=.o)

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g


$(NAME) : ${SRCB} so_long.h
	$(CC)  ${SRCB} $(CFLAGS) -o ${NAME} -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

clean :
	$(RM) $(SRCB)

fclean : clean
	$(RM) so_long

re : fclean all

bonus :${SRCB} so_long.h
	$(CC) $(CFLAGS) ${SRCB} -lmlx -framework OpenGL -framework AppKit -o ${NAME}