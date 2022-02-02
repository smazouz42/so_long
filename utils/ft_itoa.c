/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:03:06 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/02 16:37:37 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	ft_numcount(long int n)
{
	int	y;

	y = 1;
	if (n < 0)
	{
		y = 2;
		n = -n;
	}
	while (n >= 10)
	{
		y++;
		n = n / 10;
	}
	return (y);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		x;
	int		y;
	long	nb;

	nb = n;
	x = ft_numcount(n);
	y = x - 1;
	str = (char *)malloc((x + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb >= 10)
	{
		str[y] = (nb % 10) + '0';
		nb = nb / 10;
		y--;
	}
	str[x] = '\0';
	str[y] = nb + '0';
	return (str);
}
/*
int main(void)
{
	printf("%s",ft_itoa(300));
	return(0);
}
*/
