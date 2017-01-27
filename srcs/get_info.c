/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:43:15 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/27 19:34:30 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_path(char *name, char *file_name)
{
	char	*path;

	if (name[ft_strlen(name) - 1] != '/')
		check_malloc(name = ft_strjoin(name, "/"));
	check_malloc(path = ft_strjoin(name, file_name));
	return (path);
}

int		getacl(char *name)
{
	acl_t		facl;
	acl_entry_t	ae;

	facl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (facl && (acl_get_entry(facl, ACL_FIRST_ENTRY, &ae) == -1))
	{
		acl_free(facl);
		return (0);
	}
	if (facl != NULL)
	{
		acl_free(facl);
		return (1);
	}
	acl_free(facl);
	return (0);
}

char	get_type(t_stat filestat, t_file **file_data)
{
	char	ret;

	ret = '-';
	if (S_ISDIR(filestat.st_mode))
		ret = 'd';
	else if (S_ISCHR(filestat.st_mode))
		ret = 'c';
	else if (S_ISBLK(filestat.st_mode))
		ret = 'b';
	else if (S_ISFIFO(filestat.st_mode))
		ret = 'p';
	else if (S_ISLNK(filestat.st_mode))
		ret = 'l';
	else if (S_ISSOCK(filestat.st_mode))
		ret = 's';
	if ((*file_data)->type == 'c')
	{
		(*file_data)->minor = filestat.st_rdev % 256;
		(*file_data)->major = filestat.st_rdev;
	}
	return (ret);
}

char	*get_modes(t_stat filestat, t_file *file_data)
{
	char *str;

	check_malloc(str = ft_strnew(10));
	str[0] = ((filestat.st_mode & S_IRUSR) ? 'r' : '-');
	str[1] = ((filestat.st_mode & S_IWUSR) ? 'w' : '-');
	str[2] = ((filestat.st_mode & S_IXUSR) ? 'x' : '-');
	if (filestat.st_mode & S_ISUID)
		str[2] = (str[2] == '-' ? 'S' : 's');
	str[3] = ((filestat.st_mode & S_IRGRP) ? 'r' : '-');
	str[4] = ((filestat.st_mode & S_IWGRP) ? 'w' : '-');
	str[5] = ((filestat.st_mode & S_IXGRP) ? 'x' : '-');
	if (filestat.st_mode & S_ISGID)
		str[5] = (str[5] == '-' ? 'S' : 's');
	str[6] = ((filestat.st_mode & S_IROTH) ? 'r' : '-');
	str[7] = ((filestat.st_mode & S_IWOTH) ? 'w' : '-');
	str[8] = ((filestat.st_mode & S_IXOTH) ? 'x' : '-');
	if (filestat.st_mode & S_ISVTX)
		str[8] = (str[8] == '-' ? 'T' : 't');
	if ((file_data->type != 'l' && listxattr(file_data->path, NULL, 0, 0) > 0) ||
		(file_data->type == 'l' && listxattr(file_data->path, NULL, 0, XATTR_NOFOLLOW) > 0))
		str[9] = '@';
	else
		str[9] = (getacl(file_data->path) ? '+' : ' ');
	return (str);
}
