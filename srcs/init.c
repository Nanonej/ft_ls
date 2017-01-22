/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:41:32 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/22 15:57:09 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*init_file(char *name)
{
	struct stat	filestat;
	// struct passwd	*pwd;
	// struct group	*grp;
	t_file		*file_data = NULL;

	stat(name, &filestat);
	file_data = (t_file *)palloc(sizeof(t_file));
	check_malloc(file_data->filename = ft_strdup(name));
	file_data->type = get_type(filestat);
	check_malloc()
	ft_printf("Nom: %s\nType: %c\n\n", file_data->filename, file_data->type);
	return (file_data);
}

void 			init_al(t_file **files, char *name)
{
	al_add(&files, init_file(name));
}
