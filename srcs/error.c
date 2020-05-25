/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	valid_flag(char *flags)
{
	int k;

	k = 0;
	while(flags[k])
	{
		if(flags[k] == '-')
			k++;
		if(!ft_strchr("arRtl", flags[k]))
		{
			ft_putstr("ls: invalid option -- '");
			ft_putchar(flags[k]);
			ft_putstr("'\n");
			exit(1);
		}
		k++;
	}

}
void	err_handle(DIR *dir, char *path, char *flags)
{
	char *error;

	if(path[0] != '-' && dir == NULL)
	{
		error = ft_strjoin("ls: cannot access ", path);
		perror(error);
		free(error);
		exit(1);
	}	
	else if(path[0] == '-' && (path[1] != 'a' && path[1] != 'r' && path[1] != 't' && path[1] != 'l' && path[1] != 'R'))
	{
		perror(ft_strjoin("ls: invalid option -- ", path));
		exit(1);
	}
	else if (flags[0] == '-')
		valid_flag(flags);
}