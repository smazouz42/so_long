/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:12:11 by smazouz           #+#    #+#             */
/*   Updated: 2022/01/18 17:07:01 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

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
