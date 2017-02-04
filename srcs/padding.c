/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:13:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/04 17:08:19 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	**ls_padding_own(t_file **files)
{
	t_file	**save;
	char	*tmp;
	int		size;

	size = 0;
	save = files;
	while (files != al_end(save))
	{
		if ((int)ft_strlen((*files)->owner) > size)
			size = ft_strlen((*files)->owner);
		files++;
	}
	files = save;
	while (files != al_end(save))
	{
		check_malloc(tmp = ft_strnew(size));
		ft_memset(tmp, ' ', size);
		size = ft_strlen((*files)->owner);
		free_swap(&(*files)->owner, ft_strncpy(tmp, (*files)->owner, size));
		files++;
	}
	return (save);
}

static t_file	**ls_padding_grp(t_file **files)
{
	t_file	**save;
	char	*tmp;
	int		size;

	size = 0;
	save = files;
	while (files != al_end(save))
	{
		if ((int)ft_strlen((*files)->group) > size)
			size = ft_strlen((*files)->group);
		files++;
	}
	files = save;
	while (files != al_end(save))
	{
		check_malloc(tmp = ft_strnew(size));
		ft_memset(tmp, ' ', size);
		size = ft_strlen((*files)->group);
		free_swap(&(*files)->group, ft_strncpy(tmp, (*files)->group, size));
		files++;
	}
	return (save);
}

static t_file	**ls_padding_nlinks(char *flags, t_file **files)
{
	t_file	**save;
	char	*tmp;
	int		size;

	size = 0;
	save = files;
	while (files != al_end(save))
	{
		if (flags[1] == 'a' || (*files)->filename[0] != '.')
			if ((int)ft_strlen((*files)->nlinks) > size)
				size = ft_strlen((*files)->nlinks);
		files++;
	}
	files = save;
	while (files != al_end(save))
	{
		check_malloc(tmp = ft_strnew(size));
		ft_memset(tmp, ' ', size);
		size = ft_strlen((*files)->nlinks);
		free_swap(&(*files)->nlinks, ft_strncpy(tmp, (*files)->nlinks, size));
		files++;
	}
	return (save);
}

static t_file	**ls_padding_size(char *flags, t_file **files)
{
	t_file	**save;
	char	*tmp;
	int		size;

	size = 0;
	save = files;
	while (files != al_end(save))
	{
		if (flags[1] == 'a' || (*files)->filename[0] != '.')
			if ((int)ft_strlen((*files)->size) > size)
				size = ft_strlen((*files)->size);
		files++;
	}
	files = save;
	while (files != al_end(save))
	{
		check_malloc(tmp = ft_strnew(size));
		ft_memset(tmp, ' ', size);
		size = ft_strlen((*files)->size);
		free_swap(&(*files)->size, ft_strncpy(tmp, (*files)->size, size));
		files++;
	}
	return (save);
}

void			ls_padding(char *flags, t_file **files)
{
	if ((*files)->group)
	{
		files = ls_padding_grp(files);
		files = ls_padding_own(files);
		files = ls_padding_nlinks(flags, files);
		files = ls_padding_size(flags, files);
	}
}
