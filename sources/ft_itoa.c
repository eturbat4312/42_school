/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:12 by eturbat           #+#    #+#             */
/*   Updated: 2022/03/29 14:18:44 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (11);
	if (nb <= 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	nb;

	nb = n;
	i = len(nb);
	ptr = malloc(sizeof(char) * (len(nb) + 1));
	if (!ptr)
		return (0);
	if (nb == 0)
		ptr[0] = '0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	ptr[i] = '\0';
	while (nb > 0)
	{
		i--;
		ptr[i] = nb % 10 + 48;
		nb /= 10;
	}
	return (ptr);
}
