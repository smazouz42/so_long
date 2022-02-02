/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:05:44 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:56:11 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_game *player)
{
	ft_free(player->map, &player->enemy);
	free(player->mlx);
	exit(0);
	return (0);
}

int	animation(t_game *player)
{
	static int	img_counter;
	static int	duration_counter;

	if (img_counter == 5)
	{
		img_counter = 0;
		duration_counter = 0;
	}
	if (duration_counter == 5)
	{
		++img_counter;
		duration_counter = 0;
	}
	if (player->status == 'L')
		mlx_put_image_to_window(player->mlx, player->mlx_win,
			player->a_left[img_counter],
			(player->p_w - 1) * B_Z, (player->p_h - 1) * B_Z);
	else
		mlx_put_image_to_window(player->mlx, player->mlx_win,
			player->animation[img_counter],
			(player->p_w - 1) * B_Z, (player->p_h - 1) * B_Z);
	++duration_counter;
	return (0);
}

void	ft_parsing(char **av, char **tab)
{
	int	fd;

	if (ft_name_of_map(av[1]) == 0)
	{
		printf("Error:\nname of map incorrect");
		exit(0);
	}
	fd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		printf("Error:\n No such file or directory");
		exit(0);
	}
	tab[0] = ft_make_matrix(fd);
	if (!tab[0] || !*tab[0])
		exit(0);
	if (tab[0][ft_strlen(tab[0]) - 1] == '\n')
	{
		printf("Error:\n empty line");
		free(tab[0]);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	char	*tab;
	char	**tab2;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (ac == 2)
	{
		ft_parsing(av, &tab);
		tab2 = ft_split(tab, '\n');
		ft_check_map(tab2);
	}
	else
	{
		printf("Error\nthere is an error in argc");
		return (0);
	}
	ft_game(tab2);
	return (0);
}
