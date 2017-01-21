/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:13:29 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/18 15:35:57 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYLIST_H
# define ARRAYLIST_H

# include <stdlib.h>

// Must be positive
# define AL_REALLOC 256

// Can be any type
typedef char*			t_data;
// typedef int				t_data;
// typedef float			t_data;
// etc.

typedef struct			s_al
{
	t_data	*end;
	t_data	*mem;
}						t_al;

t_data		*al_create(void);
void		al_destroy(t_data **al);
void		al_add(t_data **al, t_data data);
size_t		al_size(t_data *al);
t_data		*al_end(t_data *al);

#endif
