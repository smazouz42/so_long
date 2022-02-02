/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:12:11 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:22:35 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_lstadd_back(t_enemy **enemy, t_enemy *new)
{
	t_enemy	*node;

	if (*enemy == NULL)
		*enemy = new;
	else
	{
		node = ft_lstlast(*enemy);
		node->next = new;
	}
}
