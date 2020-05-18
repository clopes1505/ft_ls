/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash-l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2020/05/18 19:37:11 by marvin           ###   ########.fr       */
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
    t_ls *head;
    store = ft_ls(store, path);
    put_blocks(store);
    head = store;
    while(head->next->name)
    {
        if(head->name[0] == '.')
        {
            head = head->next;
            continue ;
        }
        ft_putendl(head->name);
        stat_stuff(head->name);
        ft_putchar('\n');
        head = head->next;
    }
}