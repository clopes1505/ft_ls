/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash-R.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void dash_R(char *str, int indent)
{
	DIR *dir;
	struct dirent *store;
	char *path;

	if (!(dir = opendir(str)))
		return;
	while ((store = readdir(dir)) != NULL) {
		if (store->d_type == DT_DIR) {
			if (store->d_name[0] == '.')
				continue;
			path = ft_strslashjoin(str, store->d_name);
			ft_indentprint(indent);
			ft_putendl(ft_strjoin("./",store->d_name));
			dash_R(path, indent + 2);
		} else {
		ft_indentprint(indent);
		ft_putendl(store->d_name);
		}
	}
	closedir(dir);
}
