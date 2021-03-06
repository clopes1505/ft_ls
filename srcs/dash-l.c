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

void	putperms(struct stat fileperms)
{
	S_ISDIR(fileperms.st_mode) ? ft_putchar('d') : ft_putchar('-');
	fileperms.st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	fileperms.st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	fileperms.st_mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	fileperms.st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	fileperms.st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	fileperms.st_mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	fileperms.st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	fileperms.st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	fileperms.st_mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
	ft_putchar(' ');
}

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
	char	*time;

	time = ctime(&buff.st_mtime);
	time = time + 4;
	ft_putstrsize(time, 12);
}

void	stat_stuff(char *path)
{
	struct stat buff;

	lstat(path, &buff);
	ft_putchar('\t');
	putperms(buff);
	ft_putnbr(buff.st_nlink);
	ft_putchar('\t');
	put_id(buff);
	ft_putnbr(buff.st_size);
	ft_putchar('\t');
	put_time(buff);
	// if ((S_ISLNK(buff.st_mode)))
	// 	sym_link(path);
}

void	dash_l(t_ls *store, char *flags)
{
	t_ls *head;


	put_blocks(store);
	head = store;
	while(head->next)
	{
		if(!(ft_strchr(flags, 'a')))
		{
			if (head->name[0] == '.')
			{
				head = head->next;
				continue ;
			}
		}
		ft_putstr(head->name);
		stat_stuff(head->name);
		ft_putchar('\n');
		head = head->next;
	}
}