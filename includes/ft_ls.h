/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:15:07 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:17:03 by clopes           ###   ########.fr       */
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
void	dash_a(char *path, t_ls *store);
void	normie_print(t_ls *store);
t_ls	*ft_ls(t_ls *store, char *path);
void	err_handle(DIR *dir, char *path);
void	print_a(t_ls *store);
void	dash_r(char *path, t_ls *store);
void	dash_t(char *path, t_ls *store);
void	dash_l(char *path, t_ls *store);
void	put_id(struct stat buff);
void	put_time(struct stat buff);
void    put_blocks(t_ls *store);
#endif
