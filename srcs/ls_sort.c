/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:18:01 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/13 17:58:12 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_sort_name(t_file **files)
{
	size_t	i;
	size_t	j;
	t_file	*tmp;

	i = 0;
	while (i < al_size(files))
	{
		j = 0;
		while (j + 1 < al_size(files))
		{
			if (ft_strcmp(files[j]->filename, files[j + 1]->filename) > 0)
			{
				tmp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

static void		ls_sort_date(t_file **files)
{
	size_t	i;
	size_t	j;
	t_file	*tmp;

	i = 0;
	while (i < al_size(files))
	{
		j = 0;
		while (j + 1 < al_size(files))
		{
			if (files[j]->itime < files[j + 1]->itime)
			{
				tmp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

static void		ls_reverse_al(t_file **files)
{
	size_t	i;
	size_t	j;
	t_file	*tmp;

	i = 0;
	j = al_size(files) - 1;
	while (i <= j)
	{
		tmp = files[i];
		files[i] = files[j];
		files[j] = tmp;
		++i;
		--j;
	}
}

void			ls_sort_print(char *flags, t_file **files)
{
	if (al_size(files) > 0)
	{
		if (flags[4] != 't')
			ls_sort_name(files);
		if (flags[4] == 't')
			ls_sort_date(files);
		if (flags[3] == 'r')
			ls_reverse_al(files);
		if (flags[2] == 'l')
			print_opt_l(flags, files);
		else
			print_ls(flags, files);
	}
}
