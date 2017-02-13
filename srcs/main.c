/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:46:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/13 18:12:19 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*link_dest(t_file **fdata, int iflink)
{
	char	buf[1024];

	ft_bzero(buf, 1024);
	if (iflink)
		free_swap(&(*fdata)->path, ft_strjoin((*fdata)->path,
												(*fdata)->filename));
	if ((*fdata)->filename[ft_strlen((*fdata)->filename) - 1] == '/')
		(*fdata)->filename[ft_strlen((*fdata)->filename) - 1] = '\0';
	if ((readlink((*fdata)->path, buf, 1024)) == -1)
	{
		ft_ls_perror((*fdata)->path);
		return (NULL);
	}
	return (ft_strjoin(" -> ", buf));
}

static int		ls_check_link(char *name, char *flags)
{
	t_file	**lk;
	t_file	*tmp;
	char	*ldest;

	if ((tmp = fill_file_data(name, name)) == NULL)
		return (TRUE);
	lk = al_create();
	al_add(&lk, tmp);
	if ((*lk) && flags[2] == 'l' && (*lk)->type == 'l')
	{
		ls_padding(flags, lk);
		(*lk)->path[0] = '\0';
		check_malloc(ldest = link_dest(&(*lk), 1));
		ft_printf("%c%s %s %s  %s  %s %s %s%s%s%s\n", (*lk)->type, (*lk)->modes,
			(*lk)->nlinks, (*lk)->owner, (*lk)->group, (*lk)->size, (*lk)->date,
			print_color(*lk), (*lk)->filename, RESET_COLORS, ldest);
		free(ldest);
		free_al(lk);
		return (TRUE);
	}
	if ((*lk)->type == 'd')
		return (free_al(lk));
	ls_sort_print(flags, lk);
	free_al(lk);
	return (TRUE);
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
	int		i;

	check_malloc((flags = ft_strnew(5)));
	while (argc > 1 && **(++argv) == '-')
	{
		if (**argv == '-' && *(*argv + 1) == '\0')
			return (ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n"));
		get_flags(flags, *argv);
		argc--;
	}
	if (argc == 1)
		ft_ls("./", flags);
	i = argc;
	while (argc > 1)
	{
		if (!ft_strlen(*argv))
			return (ft_printf("ft_ls: fts_open: No such file or directory\n"));
		if (i != argc)
			ft_printf("%s:\n", *argv);
		ft_ls(*(argv++), flags);
		if (argc-- > 2)
			write(1, "\n", 1);
	}
	return (0);
}
