/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghrafique_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:34:16 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/24 16:05:09 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_moves(int x, t_game *player)
{
	char	*str;
	char	*m;
	char	*g;
	int		w;
	int		h;

	str = ft_itoa(x);
	m = ft_strjoin("moves :", str);
	g = mlx_xpm_file_to_image(player->mlx, "image/block.xpm", &w, &h);
	mlx_put_image_to_window(player->mlx, player->mlx_win, g, 0 * B_Z, 0 * B_Z);
	mlx_put_image_to_window(player->mlx, player->mlx_win, g, 1 * B_Z, 0 * B_Z);
	mlx_put_image_to_window(player->mlx, player->mlx_win, g, 2 * B_Z, 0 * B_Z);
	mlx_put_image_to_window(player->mlx, player->mlx_win, g, 3 * B_Z, 0 * B_Z);
	mlx_put_image_to_window(player->mlx, player->mlx_win, g, 4 * B_Z, 0 * B_Z);
	mlx_put_image_to_window(player->mlx, player->mlx_win, g, 5 * B_Z, 0 * B_Z);
	mlx_string_put(player->mlx, player->mlx_win, 5, 5, 0x00FFFF00, m);
	free (m);
}

int	key_hook(int keycode, t_game *player)
{
	if (keycode == 53)
	{
		ft_free(player->map, &player->enemy);
		ft_distroy(player);
		exit(0);
	}
	else if (keycode == D_KEY || keycode == A_KEY
		|| keycode == W_KEY || keycode == S_KEY)
		ft_move(player, keycode);
	ft_print_moves(player->mv, player);
	return (0);
}

static void	*ft_items(char **map, t_game *p, int i, int j)
{
	void	*m;
	int		w;
	int		h;

	m = NULL;
	if (map[i][j] == 'P')
		m = mlx_xpm_file_to_image(p->mlx, "image/player.xpm", &w, &h);
	else if (map[i][j] == 'C')
		m = mlx_xpm_file_to_image(p->mlx, "image/collectible.xpm", &w, &h);
	else if (map[i][j] == '1')
		m = mlx_xpm_file_to_image(p->mlx, "image/block.xpm", &w, &h);
	else if (map[i][j] == 'X')
		m = mlx_xpm_file_to_image(p->mlx, "image/zoro.xpm", &w, &h);
	else if (map[i][j] == 'E')
	{
		p->exit_x = j;
		p->exit_y = i;
		m = mlx_xpm_file_to_image(p->mlx, "image/exit.xpm", &w, &h);
	}
	return (m);
}

void	ft_put_map_items(void *mlx, void *mlx_win, char **map, t_game *player)
{
	int		i;
	int		j;
	void	*m;
	int		w;
	int		h;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' ||
				map[i][j] == '1' || map[i][j] == 'X' ||
				map[i][j] == 'E')
					m = ft_items(map, player, i, j);
			else
				m = mlx_xpm_file_to_image(mlx, "image/background.xpm", &w, &h);
			mlx_put_image_to_window(mlx, mlx_win, m, j * B_Z, i * B_Z);
			mlx_destroy_image(mlx, m);
			++j;
		}
		++i;
	}
}
