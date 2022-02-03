# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:42:04 by smazouz           #+#    #+#              #
#    Updated: 2022/02/03 18:06:52 by smazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM =	so_long.c utils/ft_strjoin.c utils/ft_split.c utils/ft_strlcpy.c utils/ft_itoa.c utils/ft_strlen.c utils/the_game.c utils/ft_lstnew.c utils/ft_lstadd_back.c utils/ft_lstlast.c utils/ft_strdup.c \
		utils/ft_check_map.c utils/ft_check_characters.c utils/ft_perser.c utils/ft_check_map_.c utils/ft_position.c utils/ft_player_move.c utils/ft_ghrafique.c\
		utils/ft_free.c utils/ft_destroy.c
SRCB = so_long_bonus.c utils_bonus/ft_strjoin_bonus.c utils_bonus/ft_split_bonus.c utils_bonus/ft_strlcpy_bonus.c utils_bonus/ft_itoa_bonus.c utils_bonus/ft_strlen_bonus.c utils_bonus/the_game_bonus.c utils_bonus/ft_lstnew_bonus.c utils_bonus/ft_lstadd_back_bonus.c utils_bonus/ft_lstlast_bonus.c utils_bonus/ft_strdup_bonus.c \
		utils_bonus/ft_check_map_bonus.c utils_bonus/ft_check_characters_bonus.c utils_bonus/ft_perser_bonus.c utils_bonus/ft_check_map__bonus.c utils_bonus/ft_position_bonus.c utils_bonus/ft_player_move_bonus.c utils_bonus/ft_ghrafique_bonus.c utils_bonus/ft_enemy_move_bonus.c \
		utils_bonus/ft_free_bonus.c utils_bonus/ft_destroy_bonus.c

OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g


$(NAME) : ${OBJM} so_long.h
	$(CC)  ${OBJM} $(CFLAGS) -o ${NAME} -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

clean :
	$(RM) $(OBJM) $(OBJB)

fclean : clean
	$(RM) so_long so_long_bonus

re : fclean all


bonus :${OBJB} so_long_bonus.h
	$(CC)  $(CFLAGS) ${OBJB} -lmlx -framework OpenGL -framework AppKit -o so_long_bonus
