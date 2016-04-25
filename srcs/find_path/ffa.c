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

int					max_flow(int source, int sink, t_bfs *b, t_allpaths *ap)
{
	int				i;
	int				max_flow;

	max_flow = 0;
	while (b_f_s(source, sink, b))
	{
		i = sink;
		while (i != source)
		{
			b->flow[T(b->pred[i], i, b->size)] += 1;
			b->flow[T(i, b->pred[i], b->size)] -= 1;
			i = b->pred[i];
		}
		max_flow += 1;
		// print_matrix(b->capacity, b->size);
		// ft_putchar('\n');
		// print_matrix(b->flow, b->size);
		save_path(source, sink, b->pred, ap);
	}
	return (max_flow);
}
