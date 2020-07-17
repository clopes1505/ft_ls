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
	if(t1.st_ctime == t2.st_ctime)
		return(t1.st_ctimespec.tv_nsec < t2.st_ctimespec.tv_nsec);
	return (t1.st_ctime < t2.st_ctime);
}
void	dash_t(t_ls *store, char *flags)
{
	t_ls	*tmp;
	char	*temp;

	//store = ft_ls(store, path, flags);
	tmp = store;
	while(store->next)
	{
		if(strchr(flags, 'r'))
		{
			if(sort_time(store->next->name, store->name))
			{
				temp = store->next->name;
				store->next->name = store->name;
				store->name = temp;
				store = tmp;
			}
			else
				store = store->next;
		}
		else {
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
	}
	store = tmp;
}