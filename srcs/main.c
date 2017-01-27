/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:46:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/27 14:20:40 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_ls(char *name, char *flags)
{
	t_file	*iflink;
	// t_file	**files;

	if (flags[2] == 'l' && (iflink = fill_file_data(name)) && iflink->type == 'l')
	{
		// print -l link
		exit(1);
	}
}

static void 	get_flags(char *flags, char *argv)
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
