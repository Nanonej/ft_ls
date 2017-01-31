/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:20:13 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/31 20:43:10 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	print_ls(char* flags, t_file **files)
{
	t_file **save;

	save = files;
	while (files != al_end(save))
	{
		if ((*files)->filename[0] != '.' || flags[1] == 'a')
		{
			ft_printf("%s%s%s\n", get_color(*files), (*files)->filename,
								RESET_COLORS);
		}
		files++;
	}
	files = save;
}
