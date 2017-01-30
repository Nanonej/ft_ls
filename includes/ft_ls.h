/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:42:20 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/29 18:35:21 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h> ////////////////////////////////////////////////////////////
# include <stdlib.h>
# include <sys/acl.h>

# define AL_REALLOC 256

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

typedef struct			s_file
{
	char					*filename;
	char					type;
	char					*modes;
	int						nlinks;
	char					*owner;
	char					*group;
	long long int			size;
	char					*date;
	int						total;
	char					*path;
	int						minor;
	int						major;
}						t_file;

typedef t_file			*t_data;

typedef struct			s_al
{
	t_data					*end;
	t_data					*mem;
}						t_al;

t_data					*al_create(void);
void					al_destroy(t_data **al);
void					al_add(t_data **al, t_data data);
size_t					al_size(t_data *al);
t_data					*al_end(t_data *al);

void					ft_ls_perror(char *s);
void					*palloc(size_t size);
void					check_malloc(void *ptr);

void					free_struct(t_file *file_data);

void					ft_ls(char *arg, char *flags);

t_file					*fill_file_data(char *name, char *path);
t_file					**ft_init_al(char *flags, char *name);

char					*get_path(char *name, char *file_name);
int						getacl(char *name);
char					get_type(t_stat filestat, t_file **files);
char					*get_modes(t_stat filestat, t_file *f_d);
char					*get_color(t_file *file_data);

void 					ft_ls_rec(name, flags);

#endif
