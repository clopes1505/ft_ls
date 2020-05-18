/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	normie_print(t_ls *store)
{
	t_ls *list;

	list = store;
	while (list->next != NULL)
	{
		if(list->name[0] == '.')
			{
				list = list->next;
				continue;
			}
		ft_putendl(list->name);
		list = list->next;
	}
}
void	print_a(t_ls *store)
{
	t_ls *list;
	
	list = store;
	while (list->next)
	{
		ft_putendl(list->name);
		list = list->next;
	}
}