/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:43:15 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/22 15:55:43 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_type(struct stat filestat)
{
	char ret;

	ret = '-';
	if (S_ISDIR(filestat.st_mode))
		ret = 'd';
	else if (S_ISCHR(filestat.st_mode))
		ret = 'c';
	else if (S_ISBLK(filestat.st_mode))
		ret = 'b';
	else if (S_ISFIFO(filestat.st_mode))
		ret = 'p';
	else if (S_ISLNK(filestat.st_mode))
		ret = 'l';
	else if (S_ISSOCK(filestat.st_mode))
		ret = 's';
	return (ret);
}
