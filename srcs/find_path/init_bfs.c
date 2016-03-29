/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:47:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 11:47:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				init_bfs(t_bfs *bfs, t_data *data)
{
	int				it;

	bfs->capacity = (int **)malloc(sizeof(int *) * data->nbroom);
	bfs->flow = (int **)malloc(sizeof(int *) * data->nbroom);
	if (!bfs->capacity || !bfs->flow)
		error_malloc();
	it = 0;
	while (it < data->nbroom)
	{
		bfs->capacity[it] = (int *)malloc(sizeof(int) * data->nbroom);
		bfs->flow[it] = (int *)malloc(sizeof(int) * data->nbroom);
		if (!bfs->capacity[it] || !bfs->flow[it])
			error_malloc();
		it++;
	}
	bfs->color = (int *)malloc(sizeof(int) * data->nbroom);
	bfs->pred = (int *)malloc(sizeof(int) * data->nbroom);
	bfs->queue = (int *)malloc(sizeof(int) * data->nbroom + 2);
	if (!bfs->color || !bfs->pred || !bfs->queue)
		error_malloc();
}