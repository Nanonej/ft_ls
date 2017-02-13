/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:42:20 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/13 17:50:07 by aridolfi         ###   ########.fr       */
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
# include <stdlib.h>
# include <sys/acl.h>
# include <errno.h>

# define AL_REALLOC 64
# define RESET_COLORS "\033[0;00m"

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

typedef struct			s_file
{
	char					*filename;
	char					type;
	char					*modes;
	char					*nlinks;
	char					*owner;
	char					*group;
	char					*size;
	char					*date;
	long int				itime;
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
void					check_malloc(void *ptr);
int						check_owner(char *flags, t_file **files);

void					free_struct(t_file *file_data);
int						free_al(t_file **files);

char					*link_dest(t_file **file_data, int iflink);
void					ft_ls(char *arg, char *flags);

t_file					*fill_file_data(char *name, char *path);
t_file					**ft_init_al(char *flags, char *name);

void					ls_sort_print(char *flags, t_file **files);

char					*get_path(char *name, char *file_name);
int						get_acl(char *name);
char					get_type(t_stat filestat, t_file **files);
char					*get_modes(t_stat filestat, t_file *f_d);
void					get_date(t_stat filestat, t_file **fdata);

void					ft_ls_rec(char *name, char *flags);

void					ls_padding(char *flags, t_file **files);

char					*print_color(t_file *file_data);
void					print_ls(char *flags, t_file **files);
void					print_opt_l(char *flags, t_file **files);

#endif
