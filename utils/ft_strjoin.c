/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:37:33 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 16:34:58 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dst;
	unsigned int	len;
	unsigned int	j;
	unsigned int	i;

	if (!s2 || !s1)
		return (NULL);
	i = 0;
	j = -1;
	len = (ft_strlen(s1)) + (ft_strlen(s2));
	dst = (char *)malloc((len + 1) * sizeof(*dst));
	if (dst == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		dst[i] = s2[j];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
