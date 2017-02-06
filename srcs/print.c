/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:20:13 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/06 14:26:26 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*print_color(t_file *file_data)
{
	if (file_data->type == 'd' && file_data->modes[7] == 'w' &&
		(file_data->modes[8] == 't' || file_data->modes[8] == 'T'))
		return ("\033[38;5;000m\033[48;5;002m");
	if (file_data->type == 'd' && file_data->modes[7] == 'w')
		return ("\033[38;5;000m\033[48;5;011m");
	if (file_data->type == 'd')
		return ("\033[38;5;014m");
	if (file_data->type == 'l')
		return ("\033[38;5;005m");
	if (file_data->type == 's')
		return ("\033[38;5;002m");
	if (file_data->type == 'p')
		return ("\033[38;5;011m");
	if (file_data->type == 'b')
		return ("\033[38;5;004m\033[48;5;014m");
	if (file_data->type == 'c')
		return ("\033[38;5;004m\033[48;5;011m");
	if (file_data->modes[2] == 's' || file_data->modes[2] == 'S')
		return ("\033[38;5;000m\033[48;5;001m");
	if (file_data->modes[5] == 's' || file_data->modes[5] == 'S')
		return ("\033[38;5;000m\033[48;5;014m");
	if (ft_strfind(file_data->modes, 'x') != -1)
		return ("\033[38;5;001m");
	return ("\033[38;5;007m");
}

void			print_ls(char *flags, t_file **files)
{
	t_file **save;

	save = files;
	while (files != al_end(save))
	{
		if ((*files)->filename[0] != '.' || flags[1] == 'a')
		{
			ft_printf("%s%s%s\n", print_color(*files), (*files)->filename,
								RESET_COLORS);
		}
		files++;
	}
	files = save;
}

void			print_total(char *flags, t_file **files)
{
	t_file	**save;
	int		n;

	n = 0;
	save = files;
	while (files != al_end(save))
	{
		if (flags[1] == 'a' || (*files)->filename[0] != '.')
			n += (*files)->total;
		files++;
	}
	ft_printf("total %d\n", n);
}

static void 	print_cfile(t_file **files)
{
	while ((*files)->major / 256 > 0)
		(*files)->major /= 256;
	ft_printf("%c%s %s %s  %s  %2d, %3d %s %s%s%s\n", (*files)->type,
				(*files)->modes, (*files)->nlinks, (*files)->owner,
					(*files)->group, (*files)->major, (*files)->minor,
						(*files)->date, print_color(*files), (*files)->filename,
						 	RESET_COLORS);
}

void			print_opt_l(char *flags, t_file **files)
{
	t_file	**tmp;
	char	*ldest;

	check_malloc(ldest = ft_strdup(""));
	ls_padding(flags, files);
	if (flags[1] == 'a' || al_size(files) > 2)
		print_total(flags, files);
	tmp = files - 1;
	while (++tmp != al_end(files))
		if (check_owner(flags, tmp))
		{
			if ((flags[1] == 'a' || (*tmp)->filename[0] != '.') &&
			(*tmp)->type != 'c')
			{
				if ((*tmp)->type == 'l')
					check_malloc(ldest = link_dest(&(*tmp), 0));
				ft_printf("%c%s %s %s  %s  %s %s %s%s%s%s\n", (*tmp)->type,
					(*tmp)->modes, (*tmp)->nlinks, (*tmp)->owner,
					(*tmp)->group, (*tmp)->size, (*tmp)->date,
					print_color(*tmp), (*tmp)->filename, RESET_COLORS, ldest);
				free_swap(&ldest, ft_strdup(""));
			}
			else if ((*tmp)->type == 'c')
				print_cfile(tmp);
		}
}
