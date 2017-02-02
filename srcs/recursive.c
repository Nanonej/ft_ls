/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:21:27 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/02 16:45:41 by aridolfi         ###   ########.fr       */
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
		if (((*tmp)->filename[0] != '.' || (*tmp)->filename[1] != 0) &&
			((*tmp)->filename[1] != '.' || (*tmp)->filename[2] != 0) &&
			((*tmp)->filename[0] != '.' || flags[1] == 'a'))
		{
			check_malloc(path = get_path(name, (*tmp)->filename));
			if ((*tmp)->type != 'l' && (dir = opendir(path)) && !closedir(dir)
									&& ft_printf("\n%s:\n", path))
				ft_ls_rec(path, flags);
			else if (errno == 13 && ft_printf("\n%s:\n", path))
				ft_ls_perror((*tmp)->filename);
			free(path);
		}
		tmp++;
	}
	free_al(files);
}
