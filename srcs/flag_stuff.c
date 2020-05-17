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

void	scan_p_arg(char *arg1, char *arg2, t_ls *store) // allows for use of arguements and paths in a single command e.g. : ft_ls libft -a, ft_ls -a libft
{
	if(arg1[0] == '-')
		scan_options(arg1, arg2, store);
	else
		scan_options(arg2, arg1, store);
}

void	scan_options(char *flags, char *path, t_ls *store) // scans selected flags moves required data to the requested function
{
	if(flags[1] == 'a')
		dash_a(path, store);
	if(flags[1] == 'r')
	 	dash_r(path, store);
	// if(flags[1] == 'l')
	// 	dash_l(path, store);
	// if(flags[1] == 't')
	// 	dash_t(path, store);
	// if(flags[1] == 'R')
	// 	dash_R(path, store);
}
void	dash_a(char *path, t_ls *store)
{
	t_ls	*tmp;
	char	*temp;

	store = ft_ls(store, path);
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
	print_a(store);
}
