/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:53:55 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:22:45 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_swap(t_game *player, int next_pos_h, int next_pos_w)
{
	if (player->map[next_pos_h][next_pos_w] == 'C')
	{
		player->map[player->p_h - 1][player->p_w - 1] = '0';
		player->map[next_pos_h][next_pos_w] = 'P';
		player->collectible--;
	}
	else if (player->map[next_pos_h][next_pos_w] == '0')
	{
		player->map[next_pos_h][next_pos_w] = 'P';
		player->map[player->p_h - 1][player->p_w - 1] = '0';
	}
}

static int	win_or_loss(t_game *player, int next_pos_h, int next_pos_w)
{
	if (player->map[next_pos_h][next_pos_w] == 'X')
	{
		printf("\x1B[31m game over");
		ft_free(player->map, &player->enemy);
		ft_distroy(player);
		exit(0);
	}
	else if (player->map[next_pos_h][next_pos_w] == 'E')
	{
		if (player->collectible == 0)
		{
			printf("\x1B[32m You win!");
			ft_free(player->map, &player->enemy);
			ft_distroy(player);
			exit(0);
		}
		else
			return (0);
	}
	return (1);
}

void	ft_move(t_game *player, int keycode)
{
	int		next_pos_h;
	int		next_pos_w;
	void	*img;
	int		w;
	int		h;

	next_pos_h = player->p_h - 1;
	next_pos_w = player->p_w - 1;
	p_and_next_p(keycode, &next_pos_h, &next_pos_w, player);
	if (player->map[next_pos_h][next_pos_w] == '1')
		return ;
	if (win_or_loss(player, next_pos_h, next_pos_w) == 0)
		return ;
	ft_swap(player, next_pos_h, next_pos_w);
	img = mlx_xpm_file_to_image(player->mlx, "image/player.xpm", &w, &h);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img, next_pos_w * B_Z, next_pos_h * B_Z);
	img = mlx_xpm_file_to_image(player->mlx, "image/background.xpm", &w, &h);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img, (player->p_w - 1) * B_Z, (player->p_h - 1) * B_Z);
	p_and_next_p(keycode, &player->p_h, &player->p_w, player);
	player->mv++;
	ft_move_enemys(player, keycode);
	mlx_destroy_image(player->mlx, img);
}
