/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:57:45 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/19 14:33:43 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	get_flags(char *flags, char *argv)
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
