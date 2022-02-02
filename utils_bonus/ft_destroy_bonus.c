/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:33:00 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:22:26 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_distroy(t_game *player)
{
	mlx_destroy_window(player->mlx, player->mlx_win);
	free(player->mlx);
}
