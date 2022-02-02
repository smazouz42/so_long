/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:58:08 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 16:36:58 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **map, t_enemy **enemy)
{
	int		x;
	t_enemy	*tmp;
	t_enemy	*head;

	x = 0;
	if (!*map)
		return ;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
	head = (*enemy);
	if (!*enemy)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*enemy = NULL;
}

void	ft_free_str(char **str)
{
	int	x;

	x = 0;
	if (!*str)
		return ;
	while (str[x])
	{
		free(str[x]);
		x++;
	}
	free(str);
}
