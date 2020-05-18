/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		sort_time(char *file, char *file2)
{
	struct stat	t1;
	struct stat t2;

	stat(file, &t1);
	stat(file2, &t2);
	return (t1.st_mtime < t2.st_mtime);
}
void	dash_t(char *path, t_ls *store)
{
	t_ls	*tmp;
	char	*temp;

	store = ft_ls(store, path);
	tmp = store;
	while(store->next->name)
	{
		if(sort_time(store->name, store->next->name))
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
	normie_print(store);
}