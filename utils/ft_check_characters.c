/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:41 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:39:17 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_loop_for_cheater(char **loop)
{
	int		x;
	int		y;
	char	s;

	x = 0;
	while (loop[x])
	{
		y = 0;
		while (loop[x][y])
		{
			s = loop[x][y];
			if (s != 'P' && s != 'E' && s != '1'
				&& s != '0' && s != 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static void	ft_zero(int *player, int *collectible, int *map_exit)
{
	*player = 0;
	*collectible = 0;
	*map_exit = 0;
}

int	ft_check_p_c_e(char **map)
{
	int	x;
	int	y;
	int	player;
	int	collectible;
	int	map_exit;

	ft_zero(&player, &collectible, &map_exit);
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'P')
				player++;
			else if (map[x][y] == 'E')
				map_exit++;
			else if (map[x][y] == 'C')
				collectible++;
		}
	}
	if (player == 1 && collectible != 0 && map_exit != 0)
		return (1);
	else
		return (0);
}

int	ft_collectible_count(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}
