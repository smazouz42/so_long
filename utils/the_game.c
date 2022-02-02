/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:01:41 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:40:22 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	ft_put_map_items(p.mlx, p.mlx_win, p.map, &p);
	mlx_hook(p.mlx_win, 2, 0, key_hook, &p);
	mlx_hook(p.mlx_win, 17, 0, ft_exit, &p);
	mlx_loop(p.mlx);
}
