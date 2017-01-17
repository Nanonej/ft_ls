/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:41:13 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 22:53:37 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(new, (size + 1));
	return (new);
}
