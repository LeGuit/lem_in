/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:43:34 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/04/25 17:43:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define CAST(type, ptr)				((type)(ptr))

void				ants_invasion(t_allpaths *p, t_data *d)
{
	t_onepath		*path;
	t_room			*room;
	int				i;
	int				j;

	path = CAST(t_onepath *, ft_vect_at(&p->paths, p->idmin));
	j = 1;
	while (j <= d->nbants)
	{
		i = 1;
		while (i < path->size)
		{
			room = CAST(t_room *, ft_vect_at(&d->anthill, path->path[i]));
			ft_printf("L%d-%s \n", j, room->name);
			i++;
		}
		j++;
	}
}
