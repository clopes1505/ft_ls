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


void	normie_print(t_ls *store) //no flags --LACKS SORTING
{
	t_ls *list;
	list = store;
	//printf("hi");
	while (list->next != NULL)
	{
		if(list->name[0] == '.')
			{
				list = list->next;
				continue;
			}
		ft_putendl(list->name);
		list = list->next;
	}
}
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
	new->next = NULL;
	closedir(dir);
	return(store);
}
void	print_a(t_ls *store)
{
	t_ls *list;
	list = store;
	ft_putendl("hi");
	while (list->next)
	{
		ft_putendl(list->name);
		list = list->next;
	}
}
void	dash_a(char *path, t_ls *store)
{
	t_ls	*tmp;
	char	*temp;

	store = ft_ls(store, path);
	tmp = store;
	while(tmp->next != NULL)
	{
		if(tmp->name == NULL)
			tmp= tmp->next;
		else if(ft_strcmp(tmp->name, tmp->next->name) > 0 && tmp->next)
		{
			temp = tmp->name;
			tmp->name = tmp->next->name;
			tmp->next->name = temp;
			tmp = store;
		}
		else
			tmp = tmp->next;
	}
	//tmp->next = NULL;
	print_a(store);
}
void	scan_options(char *flags, char *path, t_ls *store) // scans selected flags moves required data to the requested function
{
	if(flags[1] == 'a')
		dash_a(path, store);
	// if(flags[1] == 'r')
	// 	dash_r(path, store);
	// if(flags[1] == 'l')
	// 	dash_l(path, store);
	// if(flags[1] == 't')
	// 	dash_t(path, store);
	// if(flags[1] == 'R')
	// 	dash_R(path, store);
}

void	scan_p_arg(char *arg1, char *arg2, t_ls *store) // allows for use of arguements and paths in a single command e.g. : ft_ls libft -a, ft_ls -a libft
{
	if(arg1[0] == '-')
		scan_options(arg1, arg2, store);
	else
		scan_options(arg2, arg1, store);
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
	else if(argc == 3 && (argv[1][0] == '-' || argv[1][0] == '-') && !(argv[1][0] == '-' && argv[2][0] == '-'))
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
