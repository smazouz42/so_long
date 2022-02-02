/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:56:23 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 16:38:12 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	ft_keys_d_a(int keycode, int *p_w, t_game *player)
{
	if (keycode == D_KEY)
	{
		if (player->p_w > player->enemy->p_w)
			(*p_w)++;
		else
			(*p_w)--;
		player->status = 'R';
	}
	else if (keycode == A_KEY)
	{
		if (player->p_w < player->enemy->p_w)
			(*p_w)--;
		else
			(*p_w)++;
		player->status = 'L';
	}
}

void	p_and_next_e(int keycode, int *p_h, int *p_w, t_game *player)
{
	ft_keys_d_a(keycode, p_w, player);
	if (keycode == W_KEY)
	{
		if (player->p_h < player->enemy->p_h)
			(*p_h)--;
		else
			(*p_h)++;
	}
	else if (keycode == S_KEY)
	{
		if (player->p_h > player->enemy->p_h)
			(*p_h)++;
		else
			(*p_h)--;
	}
}

void	p_and_next_p(int keycode, int *p_h, int *p_w, t_game *player)
{
	if (keycode == D_KEY)
	{
		player->status = 'R';
		(*p_w)++;
	}
	else if (keycode == A_KEY)
	{
		(*p_w)--;
		player->status = 'L';
	}
	else if (keycode == W_KEY)
		(*p_h)--;
	else if (keycode == S_KEY)
		(*p_h)++;
}

void	find_player_p(t_game *player, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				player->p_h = x + 1;
				player->p_w = y + 1;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	find_enemys_p(char **map, t_enemy **enemy)
{
	int	x;
	int	y;
	int	nod;

	x = -1;
	nod = 1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'X')
			{
				if (nod == 1)
				{
					(*enemy) = ft_lstnew(x + 1, y + 1);
					nod++;
				}
				else
				{
					ft_lstadd_back(enemy, ft_lstnew(x + 1, y + 1));
				}
			}
		}
	}
}
