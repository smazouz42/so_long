/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:42 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 18:01:11 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_first_last_line(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	ft_check_lines(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '1' && str[len - 1] == '1')
		return (1);
	else
		return (0);
}

int	ft_border_of_map(char **map)
{
	size_t	len;
	int		x;

	if (!*map)
		return (0);
	len = ft_strlen(map[0]);
	x = 1;
	while (map[x])
	{
		if (ft_strlen(map[x]) != len)
			return (0);
		x++;
	}
	return (1);
}

int	ft_map_building(char **map)
{
	int	x;
	int	y;

	if (!*map || ft_border_of_map(map) == 0)
		return (0);
	x = 0;
	y = 0;
	while (map[x])
	{
		if (x == 0)
		{
			if (ft_check_first_last_line(map[x]) == 0)
				return (0);
		}
		else if (map[x + 1])
		{
			if (ft_check_lines(map[x]) == 0)
				return (0);
		}
		else
			if (ft_check_first_last_line(map[x]) == 0)
				return (0);
		x++;
	}
	return (1);
}

void	ft_check_map(char **map)
{
	if (!*map)
		return ;
	if (ft_check_p_c_e(map) == 0)
	{
		printf("Error:\nrepeated element or element missing");
		ft_free_str(map);
		exit(0);
	}
	if (ft_map_building(map) == 0)
	{
		printf("Error:\nbuilding Error");
		ft_free_str(map);
		exit(0);
	}
	if (ft_loop_for_cheater(map) == 0)
	{
		printf("Error\ncheater?????");
		ft_free_str(map);
		exit(0);
	}
}
