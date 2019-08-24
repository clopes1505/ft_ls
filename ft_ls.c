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
int	main(int ac, char **av)
{
		DIR     *dir;
		struct  dirent *sd;
        char    *temp[1024];
        int     k;

        k = 0;
		dir = opendir(".");
		if (dir == NULL)
		{
			ft_putendl("Unable to read current directory");
			exit (1);
		}
            while ((sd = readdir(dir)) != NULL)
            {
                ft_strcpy(temp[k], &sd->d_name[k]);
                ft_putstr(temp[k]);
                ft_putchar('\t');
            }
		closedir(dir);
		return (0);
}
