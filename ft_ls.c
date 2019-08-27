/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_files(char **str, int max)
{
	char	temp[1024];
	int		k;
	int		i;

	k = 0;
	i = k + 1;
	while(k < max - 1)
	{
		while(i < max)
		{
			if (ft_strcmp(str[k], str[i]) > 0)
			{
				ft_strcpy(temp, str[k]); 
    			ft_strcpy(str[k], str[i]);
    			ft_strcpy(str[i], temp);
			}
			i++;
		}
		k++;
	}
	ft_putendl(*str);
}

int		main(int argc, char **argv)
{
	DIR		*dir;
	struct dirent *sd;
	char	*str[1024];
	int		k;

	k = 0;
	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putendl("Unable to read current directory");
		exit(1);
	}
	while ((sd = readdir(dir))!= NULL)
	{
		ft_strcpy(str[k], sd->d_name);
		printf("%s", str[k]);
		k++;
	}
	printf("%s", str[k]);
	//sort_files(str, k);
	closedir(dir);
	return (0);
}
