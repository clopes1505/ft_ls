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

void	put_id(struct stat buff)
{
	struct group	*group;
	struct passwd	*pwd;

	pwd = getpwuid(buff.st_uid);
	group = getgrgid(buff.st_gid);
	ft_putstr(pwd->pw_name);
    ft_putchar(' ');
	ft_putstr(group->gr_name);
    ft_putchar(' ');
}
void	put_time(struct stat buff)
{
	char					*time;

	time = ctime(&buff.st_mtime);
    time = time + 4;
	ft_putstrsize(time, 12);
}

void    stat_stuff(char *path)
{
    struct stat buff;
    int links;

    links = 0;
    stat(path, &buff);
    links = buff.st_nlink;
    ft_putnbr(links);
    put_id(buff);
    put_time(buff);
}
void    put_blocks(t_ls *store)
{
    t_ls *tmp;

    tmp = store;
    int i;

	i = 0;
	ft_putstr("total ");
	while (tmp->next->name)
	{
		if (tmp->name[0] == '.')
        {
            tmp = tmp->next;
            continue ;
        }
        else
			i += tmp->block;
        ft_putnbr(tmp->block);
		tmp = tmp->next;
	}
	ft_putnbr(i);
	ft_putstr("\n");
}
void    dash_l(char *path, t_ls *store)
{
    // t_ls *head;
    store = ft_ls(store, path);
    put_blocks(store);
    // head = store;
    while(store->next->name)
    {
        if(store->name[0] == '.')
        {
            store = store->next;
            continue ;
        }
        ft_putendl(store->name);
        stat_stuff(store->name);
        ft_putchar('\n');
        store = store->next;
    }
}