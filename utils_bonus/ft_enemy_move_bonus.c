/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:30:17 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:22:28 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	int	check_next_pos(t_game *player, int n_p_h, int n_p_w, t_enemy *temp)
{
	char	pos;

	pos = player->map[n_p_h][n_p_w];
	if (pos == '1' || pos == 'X' || pos == 'C' || pos == 'E')
		return (0);
	if (player->map[n_p_h][n_p_w] == '0')
	{
		player->map[n_p_h][n_p_w] = 'X';
		player->map[temp->p_h - 1][temp->p_w - 1] = '0';
	}
	if (player->map[n_p_h][n_p_w] == 'P')
	{
		printf("\x1B[31m game over");
		ft_free(player->map, &player->enemy);
		ft_distroy(player);
		exit(0);
	}
	return (1);
}

void	ft_move_enemy(t_enemy *temp, t_game *player, int keycode)
{
	int		next_pos_h;
	int		next_pos_w;
	void	*img;
	int		w;
	int		h;

	next_pos_h = temp->p_h - 1;
	next_pos_w = temp->p_w - 1;
	p_and_next_e(keycode, &next_pos_h, &next_pos_w, player);
	if (check_next_pos(player, next_pos_h, next_pos_w, temp) == 0)
		return ;
	img = mlx_xpm_file_to_image(player->mlx, "image/zoro.xpm", &w, &h);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img, next_pos_w * B_Z, next_pos_h * B_Z);
	img = mlx_xpm_file_to_image(player->mlx, "image/background.xpm", &w, &h);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img, (temp->p_w - 1) * B_Z, (temp->p_h - 1) * B_Z);
	p_and_next_e(keycode, &temp->p_h, &temp->p_w, player);
	mlx_destroy_image(player->mlx, img);
}

void	ft_move_enemys(t_game *player, int keycode)
{
	t_enemy	*temp;

	temp = player->enemy;
	while (temp)
	{
		ft_move_enemy(temp, player, keycode);
		temp = temp->next;
	}
}
