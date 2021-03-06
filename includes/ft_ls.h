/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:15:07 by clopes            #+#    #+#             */
/*   Updated: 2020/05/18 19:34:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <errno.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include "../libft/libft.h"
typedef struct	s_ls
{
	char		*name;
	int			block;
	struct s_ls	*next;
}				t_ls;
void    stat_stuff(char *path);
void	scan_p_arg(char *arg1, char *arg2, t_ls *store);
void	scan_options(char *flags, char *path, t_ls *store);
void	dash_a(t_ls *store);
void	normie_print(t_ls *store);
t_ls	*ft_ls(t_ls *store, char *path, char *flags);
void	err_handle(DIR *dir, char *path, char *flags);
void	print_a(t_ls *store);
void	dash_r(t_ls *stor);
void	dash_t(t_ls *store, char *flags);
void	dash_l(t_ls *store, char *flags);
void	put_id(struct stat buff);
void	put_time(struct stat buff);
void    get_blocks(t_ls *store);
void	base_sort(t_ls *store);
void	putperms(struct stat fileperms);
void	delete_stuff(t_ls *store);
void	valid_flag(char *path);
void	dash_R(char *str, int indent);
void	sym_link(char *path);
void	put_blocks(t_ls *store);

#endif
