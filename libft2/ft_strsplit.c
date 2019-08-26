/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:29:00 by clopes            #+#    #+#             */
/*   Updated: 2019/06/26 15:50:06 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	ft_wordlen(char const *s, char c)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (s[k] == c)
		k++;
	while (s[k] != c && s[k] != '\0')
	{
		i++;
		k++;
	}
	return (i);
}

static int	ft_wordcount(char const *s, char c)
{
	unsigned int i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		x;
	int		k;
	int		i;

	k = 0;
	x = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (x < ft_wordcount(s, c))
	{
		while (s[k] == c && s[k] != '\0')
			k++;

		i = ft_wordlen(s + k, c);
		arr[x] = ft_strsub(s, k, i);
	//	printf("store : %s\n", ft_strsub(s,k,i));
		k += i;
		x++;
	}
	arr[x] = NULL;
	return (arr);
}

/*int main()
{
	char **str;
	char *arr = "   lorem   ipsum dolor    sit  amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	int i;
	char *c;
	//char *res = "iolstr";

	str = ft_strsplit(arr, ' ');
	i = 0;
	//c = ft_strdup(str[0]);
	while (i < ft_wordcount(arr, ' '))
	{
		ft_putstr(str[i]);
		//c = ft_strjoin(c, str[i]);
		i++;
	}
	//if(!(strcmp(c, res)))
		//ft_putstr("pass");
}*/
