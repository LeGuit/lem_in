/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:51:07 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/04/21 16:51:10 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define T(i,j,off)	(i + j *off)

int					max_flow(int source, int sink, t_bfs *b, t_data *d)
{
	int				increment;
	int				i;
	int				max_flow;

	max_flow = 0;
		ft_printf("bqueu: %p\n", b->queue);
	while (b_f_s(source, sink, b, d))
	{
		increment = INT_MAX;
		i = d->nbroom - 1;
		while (b->pred[i] >= 0)
		{
			increment = MIN(increment, b->capacity[T(b->pred[i], i, d->nbroom)]
				- b->flow[T(b->pred[i], i, d->nbroom)]);
			i = b->pred[i];
			ft_printf("increment: %d\n", increment);
		}
		i = d->nbroom - 1;
		while (b->pred[i] >= 0)
		{
			b->flow[T(b->pred[i], i, d->nbroom)] += increment;
			b->flow[T(i, b->pred[i], d->nbroom)] -= increment;
		}
		max_flow += increment;
	}
	return (max_flow);
}
