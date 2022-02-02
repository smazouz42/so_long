/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:06 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:49:50 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_name_of_map(char *name)
{
	char	*form;
	int		len;
	int		form_len;

	if (!name)
		return (0);
	form = ".ber";
	len = ft_strlen(name);
	form_len = 3;
	while (name[len - 1] && form_len > 0)
	{
		if (name[len - 1] == form[form_len])
		{
			len--;
			form_len--;
		}
		else
			break ;
	}
	if (form_len != 0)
		return (0);
	else
		return (1);
}

int	ft_height_of_map(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
