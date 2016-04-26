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

static void			init_ant(t_ant *a, int antnb, t_onepath *antpath)
{
	a->antid = antnb;
	a->path = antpath;
	a->move = 0;
	a->status = 0;
}

// static void			send_ants(t_ant *ants_a, t_data *d, t_allpaths *p)
// {
// 	int				i;
// 	int				maxsent;

// 	i = 0;
// 	maxsent = p->maxflow;
// 	while (i < d->nbants)
// 	{
// 		if (ants_a[i].status == 0)
// 		{
// 			ants_a[i].status = 1;
// 			maxsent--;
// 		}
// 		if (maxsent == 0)
// 			break ;
// 		i++;
// 	}
// }

static void			on_there_way(t_ant *ants_a, t_data *d, t_allpaths *p)
{
	int				nb_arrived;
	int				i;

	nb_arrived = 0;
	(void)p;
	while (nb_arrived < d->nbants)
	{
		i = 0;
		// send_ants(ants_a, d, p);
		while (i < d->nbants)
		{
			if (ants_a[i].status == 0)
				print_ant(&ants_a[i], d);
			if (ants_a[i].move == ants_a[i].path->size - 1)
			{
				nb_arrived++;
				ants_a[i].status = -1;
			}
			i++;
		}
	}
	ft_putchar('\n');
}

void				ants_invasion(t_allpaths *p, t_data *d)
{
	t_ant			*ant_array;
	t_onepath		*path;
	int				i;
	int				j;

	ft_printf("\n---- START INIT ANTS ----\n");
	ant_array = MALLOC(t_ant, d->nbants);
	i = 0;
	while (i < d->nbants)
	{
		j = 0;
		while (j < p->maxflow)
		{
			path = CAST(t_onepath *, ft_vect_at(&p->paths, j));
			init_ant(&ant_array[i], i + 1, path);
			i++;
			if (i == d->nbants)
				break ;
			j++;			
		}
	}
	print_ants_array(ant_array, d->nbants);
	ft_printf("\n---- START LAUNCH ANTS ----\n");
	on_there_way(ant_array, d, p);
}
