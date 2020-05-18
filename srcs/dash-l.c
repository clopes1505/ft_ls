/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash-l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2020/05/18 19:04:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
void dash_l(char *path, t_ls *store)
{
	store = ft_ls(store, path);
	t_ls *el;
    el = store;
	struct stat info;
	struct passwd *usr;
	struct group *grp;
	char chmod[12];

	base_sort(el);
	while (el != NULL)
	{
		lstat(el->name, &info);
		chmod[0] = (S_ISDIR(info.st_mode)) ? 'd' : '-';
		//chmod[0] = ((cur.mydirent)->d_type == DT_DIR) ? 'd' : '-';
		chmod[1] = (S_IRUSR & info.st_mode) ? 'r' : '-';
		chmod[2] = (S_IWUSR & info.st_mode) ? 'w' : '-';
		chmod[3] = (S_IXUSR & info.st_mode) ? 'x' : '-';
		chmod[4] = (S_IRGRP & info.st_mode) ? 'r' : '-';
		chmod[5] = (S_IWGRP & info.st_mode) ? 'w' : '-';
		chmod[6] = (S_IXGRP & info.st_mode) ? 'x' : '-';
		chmod[7] = (S_IROTH & info.st_mode) ? 'r' : '-';
		chmod[8] = (S_IWOTH & info.st_mode) ? 'w' : '-';
		chmod[9] = (S_IXOTH & info.st_mode) ? 'x' : '-';
		chmod[10] = '-';
		chmod[11] = '\0';
		ft_putstr(chmod);
		ft_putnbr(info.st_nlink);
		ft_putchar('\t');
		usr = getpwuid(info.st_uid);
		ft_putstr(usr->pw_name);
		grp = getgrgid(info.st_gid);
		ft_putstr(grp->gr_name);
		ft_putnbr(info.st_size);
		ft_putchar('\t');
		ft_putstr(el->name);
        ft_putchar('\n');
	//	ft_strdel(&cur.buf);
		el = el->next;
	}
}