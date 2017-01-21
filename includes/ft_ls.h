/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:42:20 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/21 21:15:47 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h> ////////////////////////////////////////////////////////////
# include <stdlib.h>

# define AL_REALLOC 256

typedef struct s_file	t_data;

typedef struct			s_al
{
	t_data					*end;
	t_data					*mem;
}						t_al;

typedef struct			s_files
{
	char					*filename;
	char					type;
	char*					modes;
	int						nlinks;
	char					*owner;
	char					*group;
	long long int			size;
	char					*date;
	char					*path;
	struct s_file			*prev;
	struct s_file			*next;
}						t_files;

t_data					*al_create(void);
void					al_destroy(t_data **al);
void					al_add(t_data **al, t_data data);
size_t					al_size(t_data *al);
t_data					*al_end(t_data *al);

void					ft_ls_perror(char *s);
void					check_malloc(void *ptr);

void 					ft_ls(char *arg, char *flags);
void 					ft_lsrec(char *directory, char *flags);

#endif
