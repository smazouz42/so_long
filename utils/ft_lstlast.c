/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:23:40 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 16:37:55 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

t_enemy	*ft_lstlast(t_enemy *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL )
	{
		lst = lst->next;
	}
	return (lst);
}
