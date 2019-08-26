/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:44:22 by clopes            #+#    #+#             */
/*   Updated: 2019/06/24 11:43:50 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (dst[k])
		k++;
	while (src[i])
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	dst[k] = '\0';
	return (dst);
}
