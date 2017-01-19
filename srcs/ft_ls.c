/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:46:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/19 15:18:14 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	main(int argc, char **argv)
{
	char	*flags;

	argv++;
	check_alloc((flags = ft_strnew(5)));
	while (argc > 1 && **argv == '-' && ft_strlen(*argv) > 1)
	{
		get_flags(flags, *argv);
		argv++;
		argc--;
	}
	// ft_printf("R: %c\n", flags[0]);
	// ft_printf("a: %c\n", flags[1]);
	// ft_printf("l: %c\n", flags[2]);
	// ft_printf("r: %c\n", flags[3]);
	// ft_printf("t: %c\n", flags[4]);
	while (argc > 1)
	{
		ft_printf("Dir :%s\n", *argv);
		argv++;
		argc--;
	}
	ft_strdel(&flags);
	return (0);
}
