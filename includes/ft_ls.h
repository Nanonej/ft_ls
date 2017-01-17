/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:42:20 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/17 16:34:19 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h> ////////////////////////////////////////////////////////////

typedef struct	s_files
{
	char			*filename;
	char			type;
	int				modes;
	int				nlinks;
	char			*owner;
	char			*group;
	long long int	size;
	char			*date;
	char			*path;
	struct s_file	*prev;
	struct s_file	*next;
}				t_files;

#endif
