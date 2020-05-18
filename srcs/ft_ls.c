/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:16 by clopes            #+#    #+#             */
/*   Updated: 2019/08/22 16:21:18 by clopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	delete_stuff(t_ls *store)
{
	t_ls *current;
	t_ls *next;

	current = store;
	while (current->next != NULL)
		current = current->next;
	next = current->next;
	free(next);
}
void	base_sort(t_ls *store)
{
	t_ls	*tmp;
	char	*temp;

	tmp = store;
	while(store->next->name)
	{
		if(ft_strcmp(store->name, store->next->name) > 0)
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
}

void	err_handle(DIR *dir, char *path)
{
	char *error;

	if(path[0] != '-' && dir == NULL)
	{
		error = ft_strjoin("ls: cannot access ", path);
		perror(error);
		exit(1);
	}	
	else if(path[0] == '-' && (path[1] != 'a' && path[1] != 'r' && path[1] != 't' && path[1] != 'l' && path[1] != 'R'))
	{
		perror(ft_strjoin("ls: invalid option -- ", path));
		exit(1);
	}
}

t_ls	*ft_ls(t_ls *store, char *path)
{
	DIR		*dir;
	struct dirent *sd;
	t_ls *new;
	struct stat	ss;

	new = (t_ls*)malloc(sizeof(t_ls));
	store = new;
	dir = opendir(path);
	err_handle(dir, path);
	while ((sd = readdir(dir)))
	{
		new->name = sd->d_name;
		new->block = ss.st_blocks;
		lstat(new->name, &ss);
		new->next = (t_ls*)malloc(sizeof(t_ls));
		new = new->next;
	}
	new = NULL;
	closedir(dir);
	return(store);
}

int		main(int argc, char **argv)
{
	t_ls *store;
	char *path;

	path = ".";
	store  = NULL;
	if(argc == 2 && argv[1][0] != '-')
	{
		path = ft_strdup(argv[1]);
		store = ft_ls(store, path);
		base_sort(store);
		normie_print(store);
		delete_stuff(store);
	}
	else if(argc == 2 && argv[1][0] == '-')
		scan_options(argv[1], path, store);
	else if(argc == 3 && (argv[1][0] == '-' || argv[2][0] == '-') && !(argv[1][0] == '-' && argv[2][0] == '-'))
		scan_p_arg(argv[1], argv[2], store);
	else if(argc == 1)
	{
		store = ft_ls(store, path);
		base_sort(store);
		normie_print(store);
		delete_stuff(store);
	}
	return (0);
}