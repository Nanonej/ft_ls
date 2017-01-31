/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:21:27 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/31 20:49:01 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_ls_rec(char *name, char *flags)
{
	char	*path;
	t_file	**files;
	t_file	**tmp;
	DIR		*dir;

	check_malloc(files = ft_init_al(flags, name));
	tmp = files;
	while (tmp != al_end(files))
	{
		/*if (ft_strequ((*tmp)->filename, ".") && ft_strequ((*tmp)->filename,
			"..") && ((*tmp)->filename[0] != '.' || flags[1] == 'a'))*/
		if (((*tmp)->filename[0] != '.' || (*tmp)->filename[1] != 0) && ((*tmp)->filename[1] != '.'
			|| (*tmp)->filename[2] != 0) && ((*tmp)->filename[0] != '.' || flags[1] == 'a'))
		{
			check_malloc(path = get_path(name, (*tmp)->filename));
			ft_printf("\n%s:\n", path);
			if ((*tmp)->type != 'l' && (dir = opendir(path)))
			{
				closedir(dir);
				ft_ls_rec(path, flags);
			}
			else if (!dir)
				ft_ls_perror((*tmp)->filename);
			free(path);
		}
		tmp++;
	}
	free_al(files);
}
