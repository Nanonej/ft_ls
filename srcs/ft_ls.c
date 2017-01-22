/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:14:46 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/22 14:54:16 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_lsrec(char *arg, char *flags)
{
	DIR				*dir;
	struct dirent	*dirent;
	t_file			**files;

	files = al_create();
	if (!(dir = opendir(arg)) && flags[0] != 'R')
	{
		ft_ls_perror(arg);
		return ;
	}
	while ((dirent = readdir(dir)))
		init_al(files, dirent->d_name);
	closedir(dir);
}

void 	ft_ls(char *arg, char *flags)
{
	if (flags[0] == 'R')
		ft_lsrec(arg, flags);
}

// void 	ft_init_dfile(t_files *dfile)
// {
// 	if (!(dfile = (t_files*)malloc(sizeof(t_files))))
// 		return (NULL);
// 	dfile->filename
// }
