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

int					max_flow(int source, int sink, t_bfs *bfs, t_data *data)
{
	int				increment;
	int				it;
	int				max_flow;

	max_flow = 0;
	while (b_f_s(source, sink, bfs, data))
	{
		increment = INT_MAX;
		it = data->nbroom - 1;
		while (bfs->pred[it] >= 0)
		{
			increment = MIN(increment, bfs->capacity[bfs->pred[it]][it]
				- bfs->flow[bfs->pred[it]][it]);
			it = bfs->pred[it];
		}
		it = data->nbroom - 1;
		while (bfs->pred[it] >= 0)
		{
			bfs->flow[bfs->pred[it]][it] += increment;
			bfs->flow[it][bfs->pred[it]] -= increment;
		}
		max_flow += increment;
	}
	return (max_flow);
}
