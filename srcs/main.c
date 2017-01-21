/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:46:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/21 15:58:06 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	while (argc >= 1)
	{
		if (argc >= 2)
			ft_ls(*argv, flags);
		else
			ft_ls(".", flags);
		argv++;
		argc--;
	}
	ft_strdel(&flags);
	return (0);
}
