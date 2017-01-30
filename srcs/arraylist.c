/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:13:33 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/29 18:28:35 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data		*al_create(void)
{
	t_al	*al;

	al = palloc(sizeof(t_al) + (sizeof(t_data) * AL_REALLOC));
	al->end = (t_data*)(al + 1);
	al->mem = al->end + AL_REALLOC;
	return (al->end);
}

void		al_destroy(t_data **start)
{
	free((t_al*)(*start) - 1);
	*start = NULL;
}

void		al_add(t_data **start, t_data data)
{
	t_al	*al;
	t_al	*tmp;

	al = (t_al*)(*start) - 1;
	if (al->end == al->mem)
	{
		tmp = al;
		al = palloc(sizeof(t_al)
				+ (sizeof(t_data) * (AL_REALLOC + (tmp->end - *start))));
		al->end = (t_data*)(al + 1);
		while (*start != tmp->end)
		{
			*al->end = **start;
			al->end++;
			(*start)++;
		}
		al->mem = al->end + AL_REALLOC;
		*start = (t_data*)(al + 1);
	}
	*al->end = data;
	al->end++;
}

size_t		al_size(t_data *start)
{
	t_al	*al;

	al = (t_al*)start - 1;
	return (al->end - start);
}

t_data		*al_end(t_data *start)
{
	t_al	*al;

	al = (t_al*)start - 1;
	return (al->end);
}
