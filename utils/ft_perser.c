/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:44:20 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 17:58:28 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_make_matrix(int fd)
{
	char	*tab;
	char	*str;
	char	*temp;

	tab = NULL;
	str = readi(fd);
	while (str)
	{
		if (str[0] == '\n')
		{
			printf("Error:\n Empty line");
			exit(0);
		}
		if (!tab)
			tab = ft_strdup(str);
		else
		{
			temp = tab;
			tab = ft_strjoin(tab, str);
			free(temp);
		}
		free(str);
		str = readi(fd);
	}
	return (tab);
}

char	*readi(int fd)
{
	char	*buffer;
	char	buff[1];
	int		i;

	i = 1;
	buffer = ft_strdup("");
	while (i)
	{
		i = read(fd, buff, 1);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer = ft_sstrjoin(buffer, buff);
		if (buff[0] == '\n')
			break ;
	}
	if (buffer[0] == '\0')
		return (free(buffer), NULL);
	return (buffer);
}

char	*ft_sstrjoin(char	*s1, char *c)
{
	char	*al;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	al = malloc(len + 2);
	if (al == 0)
		return (0);
	while (s1[i])
	{
		al[i] = s1[i];
		i++;
	}
	al[len] = c[0];
	al[len + 1] = '\0';
	free(s1);
	return (al);
}
