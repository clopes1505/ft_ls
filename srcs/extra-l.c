/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra-l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2020/05/18 19:37:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	put_blocks(t_ls *store)
{
	t_ls *tmp;
	int i;

	tmp = store;
	i = 0;
	ft_putstr("total ");
	while (tmp->next)
	{
		if (tmp->name[0] == '.')
		{
			tmp = tmp->next;
			continue ;
		}
		else
			i += tmp->block;
		tmp = tmp->next;
	}
	ft_putnbr(i);
	ft_putstr("\n");
}

void	sym_link(char *path)
{
	char buff[100];

	ft_memset(buff, 0, sizeof(buff));
	readlink(path, buff, 100);
	ft_putstr(" -> ");
	ft_putstr(buff);
}