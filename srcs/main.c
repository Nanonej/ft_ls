/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:46:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/06 22:35:22 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*link_dest(t_file **fdata, int iflink)
{
	char	buf[4096];

	if (iflink)
		check_malloc((*fdata)->path = ft_strjoin((*fdata)->path,
												(*fdata)->filename));
	if ((*fdata)->filename[ft_strlen((*fdata)->filename) - 1] == '/')
		(*fdata)->filename[ft_strlen((*fdata)->filename) - 1] = '\0';
	if ((*fdata)->filename[0] != '/')
		check_malloc((*fdata)->filename = ft_strjoin("/", (*fdata)->filename));
	if ((readlink((*fdata)->path, buf, 4096)) == -1)
	{
		ft_ls_perror((*fdata)->path);
		return (NULL);
	}
	return (ft_strjoin(" -> ", buf));
}

static int		ls_check_link(char *name, char *flags)
{
	t_file	**iflink;
	char	*ldest;

	iflink = al_create();
	al_add(&iflink, fill_file_data(name, name));
	if ((*iflink) && flags[2] == 'l' && (*iflink)->type == 'l')
	{
		ls_padding(flags, iflink);
		(*iflink)->path[0] = '\0';
		check_malloc(ldest = link_dest(&(*iflink), 1));
		ft_printf("%c%s %s %s  %s  %s %s %s%s%s%s\n", (*iflink)->type,
			(*iflink)->modes, (*iflink)->nlinks, (*iflink)->owner,
			(*iflink)->group, (*iflink)->size, (*iflink)->date,
			print_color(*iflink), (*iflink)->filename, RESET_COLORS, ldest);
		free_al(iflink);
		return (TRUE);
	}
	free_al(iflink);
	return (!(*iflink) ? TRUE : FALSE);
}

void			ft_ls(char *name, char *flags)
{
	t_file	**files;

	if (ls_check_link(name, flags))
		return ;
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
	while (1 < 2)
		;
	return (0);
}
