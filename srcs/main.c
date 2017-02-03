/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:46:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/03 14:38:13 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls(char *name, char *flags)
{
	t_file	*iflink;
	t_file	**files;

	if (!(iflink = fill_file_data(name, name)))
		return ;
	if (iflink && flags[2] == 'l' && iflink->type == 'l')
	{
		ls_padding(flags, &iflink);
		//
		ft_printf("[WIP] - %c%s    %d %s    %s    %lld %s %s\n", iflink->type,
					iflink->modes, iflink->nlinks, iflink->owner,
					 iflink->group, iflink->size, iflink->date,
					  iflink->filename);
		return ;
	}
	free_struct(iflink);
	if (flags[0] == 'R')
		ft_ls_rec(name, flags);
	else
	{
		check_malloc(files = ft_init_al(flags, name));
		free_al(files);
	}
}

static void		get_flags(char *flags, char *argv)
{
	argv++;
	while (*argv)
	{
		if (ft_strfind("Ralrt", *argv) != -1)
			flags[ft_strfind("Ralrt", *argv)] = *argv;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", *argv);
			ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
			exit(EXIT_FAILURE);
		}
		argv++;
	}
}

int				main(int argc, char **argv)
{
	char	*flags;

	argv++;
	check_malloc((flags = ft_strnew(5)));
	while (argc > 1 && **argv == '-' && ft_strlen(*argv) > 1)
	{
		get_flags(flags, *argv);
		argv++;
		argc--;
	}
	if (argc == 1)
		ft_ls("./", flags);
	while (argc > 1)
	{
		if (!ft_strlen(*argv))
			return (ft_printf("ft_ls: fts_open: No such file or directory\n"));
		ft_ls(*argv, flags);
		argv++;
		argc--;
	}
	ft_strdel(&flags);
	return (0);
}
