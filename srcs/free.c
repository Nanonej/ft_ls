/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:42:59 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/06 17:10:05 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_struct(t_file *file_data)
{
	if (file_data->filename)
		free(file_data->filename);
	if (file_data->modes)
		free(file_data->modes);
	if (file_data->owner)
		free(file_data->owner);
	if (file_data->group)
		free(file_data->group);
	if (file_data->date)
		free(file_data->date);
	if (file_data->path)
		free(file_data->path);
	free(file_data);
}

void	free_al(t_file **files)
{
	t_file **tmp;

	if (*files)
	{
		tmp = files;
		while (tmp != al_end(files))
		{
			free_struct(*tmp);
			tmp++;
		}
	}
	al_destroy(&files);
}
