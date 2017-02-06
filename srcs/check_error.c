/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:54:07 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/06 14:48:59 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_perror(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(s);
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		ft_ls_perror(NULL);
		exit(EXIT_FAILURE);
	}
}

int		check_owner(char *flags, t_file **files)
{
	if (!(*files)->owner && (flags[1] == 'a' || (*files)->filename[0] != '.'))
	{
		ft_printf("ft_ls: %s: Error file or directory haven't an owner\n",
					(*files)->filename);
		return (0);
	}
	return (1);
}
