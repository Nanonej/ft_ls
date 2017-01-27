/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:41:32 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/27 14:37:07 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void 	init_file(t_file *file_data)
{
	file_data->filename = NULL;
	file_data->type = 0;
	file_data->modes = NULL;
	file_data->nlinks = 0;
	file_data->owner = NULL;
	file_data->group = NULL;
	file_data->size = 0;
	file_data->date = NULL;
	file_data->total = 0;
	file_data->path = NULL;
	file_data->minor = 0;
	file_data->major = 0;
}

t_file			*fill_file_data(char *name)
{
	t_stat		filestat;
	t_pwd		*pwd;
	t_grp		*grp;
	t_file		*file_data;

	init_file(file_data = (t_file *)palloc(sizeof(t_file)));
	check_malloc(file_data->filename = ft_strdup(name));
	if (lstat(name, &filestat) == -1)
	{
		ft_ls_perror(name);
		return (file_data);
	}
	file_data->type = get_type(filestat, &file_data);
	check_malloc(file_data->modes = get_modes(filestat, file_data));
	file_data->nlinks = filestat.st_nlink;
	if ((pwd = getpwuid(filestat.st_uid)))
		check_malloc(file_data->owner = ft_strdup(pwd->pw_name));
	if ((grp = getgrgid(filestat.st_gid)))
		check_malloc(file_data->group = ft_strdup(grp->gr_name));
	file_data->size = filestat.st_size;
	check_malloc(file_data->date = ft_strsub(ctime(&filestat.st_mtime), 4, 12));
	file_data->total = filestat.st_blocks;
	return (file_data);
}

// t_file			**ft_init(char *name)
// {
// 	t_file		**files;
//
// 	files = al_create();
// 	al_add(&files, fill_file_data(name));
// 	if (!(dir = opendir(arg)))
// 	{
// 		ft_ls_perror(arg);
// 		return ;
// 	}
// 	while ((dirent = readdir(dir)))
// 		init_al(files, dirent->d_name);
// 	closedir(dir);
// 	return (files);
// }
