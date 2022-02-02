/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:01:41 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:23:02 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	animation_player(t_game *p)
{
	int	h;
	int	n;

	p->animation[0] = mlx_xpm_file_to_image(p->mlx, "image/sanji1.xpm", &n, &h);
	p->animation[1] = mlx_xpm_file_to_image(p->mlx, "image/sanji2.xpm", &n, &h);
	p->animation[2] = mlx_xpm_file_to_image(p->mlx, "image/sanji3.xpm", &n, &h);
	p->animation[3] = mlx_xpm_file_to_image(p->mlx, "image/sanji4.xpm", &n, &h);
	p->animation[4] = mlx_xpm_file_to_image(p->mlx, "image/sanji5.xpm", &n, &h);
	p->animation[5] = mlx_xpm_file_to_image(p->mlx, "image/sanji6.xpm", &n, &h);
}

static void	a_left(t_game *p)
{
	int	h;
	int	w;

	p->a_left[0] = mlx_xpm_file_to_image(p->mlx, "image/sanji1_l.xpm", &w, &h);
	p->a_left[1] = mlx_xpm_file_to_image(p->mlx, "image/sanji2_l.xpm", &w, &h);
	p->a_left[2] = mlx_xpm_file_to_image(p->mlx, "image/sanji3_l.xpm", &w, &h);
	p->a_left[3] = mlx_xpm_file_to_image(p->mlx, "image/sanji4_l.xpm", &w, &h);
	p->a_left[4] = mlx_xpm_file_to_image(p->mlx, "image/sanji5_l.xpm", &w, &h);
	p->a_left[5] = mlx_xpm_file_to_image(p->mlx, "image/sanji6_l.xpm", &w, &h);
}

void	ft_game(char **map)
{
	t_game	p;
	int		h;
	int		w;
	t_enemy	*enemy;

	enemy = NULL;
	if (!*map)
		return ;
	find_player_p(&p, map);
	p.map = map;
	p.mv = 0;
	w = ft_strlen(map[0]);
	h = ft_height_of_map(map);
	p.collectible = ft_collectible_count(map);
	find_enemys_p(p.map, &enemy);
	p.enemy = enemy;
	p.mlx = mlx_init();
	p.mlx_win = mlx_new_window(p.mlx, w * B_Z, h * B_Z, "so_long");
	animation_player(&p);
	a_left(&p);
	mlx_loop_hook(p.mlx, animation, &p);
	ft_put_map_items(p.mlx, p.mlx_win, p.map, &p);
	mlx_hook(p.mlx_win, 2, 0, key_hook, &p);
	mlx_hook(p.mlx_win, 17, 0, ft_exit, &p);
	mlx_loop(p.mlx);
}
