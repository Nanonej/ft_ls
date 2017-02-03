/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:41:32 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/03 15:43:58 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void 	init_file(t_file *file_data)
{
	file_data->filename = NULL;
	file_data->type = 0;
	file_data->modes = NULL;
	file_data->nlinks = NULL;
	file_data->owner = NULL;
	file_data->group = NULL;
	file_data->size = NULL;
	file_data->date = NULL;
	file_data->total = 0;
	file_data->path = NULL;
	file_data->minor = 0;
	file_data->major = 0;
}

t_file			*fill_file_data(char *name, char *path)
{
	t_stat		filestat;
	t_pwd		*pwd;
	t_grp		*grp;
	t_file		*file_data;

	init_file(file_data = (t_file *)palloc(sizeof(t_file)));
	check_malloc(file_data->filename = ft_strdup(name));
	check_malloc(file_data->path = ft_strdup(path));
	if (lstat(path, &filestat) == -1)
	{
		ft_ls_perror(path);
		free_struct(file_data);
		return (NULL);
	}
	file_data->type = get_type(filestat, &file_data);
	check_malloc(file_data->modes = get_modes(filestat, file_data));
	check_malloc(file_data->nlinks = ft_strdup(ft_itoa(filestat.st_nlink)));
	if ((pwd = getpwuid(filestat.st_uid)))
		check_malloc(file_data->owner = ft_strdup(pwd->pw_name));
	if ((grp = getgrgid(filestat.st_gid)))
		check_malloc(file_data->group = ft_strdup(grp->gr_name));
	check_malloc(file_data->size = ft_strdup(ft_itoa(filestat.st_size)));
	check_malloc(file_data->date = ft_strsub(ctime(&filestat.st_mtime), 4, 12));
	file_data->total = filestat.st_blocks;
	return (file_data);
}

t_file			**ft_init_al(char *flags, char *name)
{
	DIR			*dir;
	t_dirent	*dirent;
	t_file		**files;
	char		*path;

	if (name[ft_strlen(name) - 1] != '/')
		check_malloc(name = ft_strjoin(name, "/"));
	if (!(dir = opendir(name)))
	{
		ft_ls_perror(name);
		return ((files = NULL));
	}
	files = al_create();
	while ((dirent = readdir(dir)))
	{
		check_malloc(path = get_path(name, dirent->d_name));
		al_add(&files, fill_file_data(dirent->d_name, path));
		free(path);
	}
	if (flags[2] == 'l')
		print_opt_l(flags, files);
	else
		print_ls(flags, files);
	closedir(dir);
	return (files);
}
