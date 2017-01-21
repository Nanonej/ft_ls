/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:54:07 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/21 13:56:23 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_ls_perror(char *s)
{
	write(2, "ft_ls: ", 7);
	perror(s);
	return (NULL);
}

void	*check_malloc(void *ptr)
{
	if (!ptr)
	{
		ft_ls_perror(NULL);
		exit(EXIT_FAILURE);
	}
}
