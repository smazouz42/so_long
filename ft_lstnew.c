/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:25:02 by smazouz           #+#    #+#             */
/*   Updated: 2022/01/18 17:14:04 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_enemy	*ft_lstnew(int p_h, int p_w)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->p_h = p_h;
	enemy->p_w = p_w;
	enemy->next = NULL;
	return (enemy);
}
