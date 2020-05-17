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

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <errno.h>
#include "../libft/libft.h"
typedef struct		s_ls
{
	char		*name;

	struct s_ls	*next;
}               t_ls;
#endif