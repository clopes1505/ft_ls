
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


void	print_list(t_ls *store)
{
	t_ls *list;
	list = store;

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
void	err_handle(DIR *dir,)
{

}

t_ls	*ft_ls(t_ls *store, char *path) //standard ls (no flags)
{
	DIR		*dir;
	struct dirent *sd;
	char *error;
	t_ls *new;

	new = (t_ls*)malloc(sizeof(t_ls));
	store = new;
	dir = opendir(path);
	if (dir == NULL)
		err_handle(sd); 
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

int		main(int argc, char **argv)
{
	t_ls *store;
	char *path;
	store  = NULL;
	if(argc == 2 && argv[1][0] != '-')
	{
		path = ft_strdup(argv[1]);
		ft_ls(store, path);
	}
	else
		ft_ls(store, ".");
	return (0);
}

// void	flags(char *flags) // tells program what function to do dependant on the flag
// {
// 	if(flags[1] == 'a')
// 		dash_a;
// 	if(flags[1] == 'r')
// 		dash_r;
// 	if(flags[1] == 'l')
// 		dash_l;
// 	if(flags[1] == 't')
// 		dash_t;
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
// int		is_flag(char *str) //checks if there is a flag in the arguments passed
// {
// 	if(str[0] == '-')
// 		return(1);
// 	return(0);
// }
// int		main(int argc, char **argv)
// {
// 	if(argc == 2)
// 	{
// 		if(is_flag(argv[1]))
// 			flags(argv[1]);	
// 	}
// 	else if(argc == 1)
// 		ft_ls();
// 	return(0);
// }
// int		main()//)t argc, char **argv)
// {
// 	ft_ls();
// 	return(0);
// }
