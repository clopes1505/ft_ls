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



void	err_handle(DIR *dir, char *path) //handles all errors
{
	if(path[0] != '-' && dir == NULL)
	{
		perror(ft_strjoin("ls: cannot access ", path));
		exit(1);
	}	
	else if(path[0] == '-' && dir == NULL)
	{
		perror(ft_strjoin("ls: invalid option -- ", path));
		exit(1);
	}
}

t_ls	*ft_ls(t_ls *store, char *path) //stores all the required info (could be optimized with more time in the future)
{
	DIR		*dir;
	struct dirent *sd;
	t_ls *new;
	
	new = (t_ls*)malloc(sizeof(t_ls));
	store = new;
	dir = opendir(path);
	err_handle(dir, path);
	while ((sd = readdir(dir)))
	{
		new->name = sd->d_name;
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
		normie_print(store);
	}
	else if(argc == 2 && argv[1][0] == '-')
		scan_options(argv[1], path, store);
	else if(argc == 3 && (argv[1][0] == '-' || argv[2][0] == '-') && !(argv[1][0] == '-' && argv[2][0] == '-'))
		scan_p_arg(argv[1], argv[2], store);
	else if(argc == 1)
	{
		store = ft_ls(store, path);
		normie_print(store);
	}
	return (0);
}

// void	flags(char *flags) // tells program what function to do dependant on the flag
// {
	
// }
// void	dash_a() //displays every item including hidden .files
// {

// }
// void	dash_r() //reverse order
// {

// }
// void	dash_t() //sort by modification time, newest first
// {

// }
// void	dash_l() //long list version
// {

// }
