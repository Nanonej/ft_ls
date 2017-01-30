/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:54:07 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/29 18:29:03 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_perror(char *s)
{
	write(2, "ft_ls: ", 7);
	perror(s);
}

void	*palloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(1);
	ft_bzero(ptr, size);
	return (ptr);
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		ft_ls_perror(NULL);
		exit(EXIT_FAILURE);
	}
}
