/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:32:20 by gwoodwar          #+#    #+#             */
/*   itpdated: 2016/03/23 13:32:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					max_flow(int source, int sink, t_bfs *bfs, t_data *data)
{
	int				increment;
	int				it;

	while (bfs(source, sink))
	{
		increment = INT_MAX;
		it = data->nbroom - 1;
		while (bfs->pred[it] >= 0)
		{
			increment = MIN(increment, bfs->capacity[bfs->pred[it]][it]
				- bfs->flow[bfs->pred[it]][it]);
			it = bfs->pred[it];
		}	

	}
}