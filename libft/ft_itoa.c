/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:41:08 by clopes            #+#    #+#             */
/*   Updated: 2019/06/18 16:38:11 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_numlen(long n)
{
	int k;

	k = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		k++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}

char			*ft_itoa(int n)
{
	char	*num;
	size_t	len;
	long	nb;

	nb = n;
	len = ft_numlen(nb);
	if (!(num = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len--] = '\0';
	if (nb == 0)
	{
		num[0] = 48;
		return (num);
	}
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		num[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (num);
}
