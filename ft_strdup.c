/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:12:57 by smazouz           #+#    #+#             */
/*   Updated: 2022/01/19 17:13:09 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	*ft_strdup(const char *s1)
{
	unsigned int	s;
	unsigned int	i;
	char			*dst;

	i = 0;
	s = 0;
	while (s1[s] != '\0')
		s++;
	dst = (char *)malloc((s + 1) * sizeof(*dst));
	if (dst == 0)
		return (NULL);
	while (i < s)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}