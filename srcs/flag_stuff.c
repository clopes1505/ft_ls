/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	scan_p_arg(char *arg1, char *arg2, t_ls *store)
{
	if(arg1[0] == '-')
		scan_options(arg1, arg2, store);
	else
		scan_options(arg2, arg1, store);
}

void	scan_options(char *flags, char *path, t_ls *store)
{
	store = ft_ls(store, path, flags);
	valid_flag(flags);
	if (ft_strchr(flags, 'R'))
		dash_R(path, 0);
	else 
	{
		if (ft_strchr(flags, 'a'))
		{
			dash_a(store);
			if (ft_strchr(flags, 'r'))
				dash_r(store);
			if (ft_strchr(flags, 't'))
				dash_t(store, flags);
			if (ft_strchr(flags, 'l'))
				dash_l(store, flags);
			else
				print_a(store);
		}
		else if (!(ft_strchr(flags, 'a')))
		{
			dash_a(store);
			if (ft_strchr(flags, 'r'))
				dash_r(store);
			if (ft_strchr(flags, 't'))
				dash_t(store, flags);
			if (ft_strchr(flags, 'l'))
				dash_l(store, flags);
			else
				normie_print(store);
		}
	}
	delete_stuff(store);
}
void	dash_a(t_ls *store)
{
	t_ls	*tmp;
	char	*temp;

	tmp = store;
	while(store->next->name)
	{
		if(ft_strcmp(store->name, store->next->name) > 0)
		{
			temp = store->name;
			store->name = store->next->name;
			store->next->name = temp;
			store = tmp;
		}
		else
			store = store->next;
	}
	store = tmp;
}
void	dash_r(t_ls *store)
{
	t_ls	*tmp;
	char	*temp;

	tmp = store;
	while(store->next->name)
	{
		if(ft_strcmp(store->name, store->next->name) < 0)
		{
			temp = store->name;
			store->name = store->next->name;
			store->next->name = temp;
			store = tmp;
		}
		else
			store = store->next;
	}
	store = tmp;
}

