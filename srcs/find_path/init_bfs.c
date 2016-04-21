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

void					init_bfs(t_bfs *bfs, int nbroom)
{
	bfs->capacity = (int *)malloc(sizeof(int) * nbroom * nbroom);
	ft_bzero(bfs->capacity, nbroom * nbroom);
	bfs->flow = (int *)malloc(sizeof(int) * nbroom * nbroom);
	ft_bzero(bfs->flow, nbroom * nbroom * nbroom);
	bfs->color = (int *)malloc(sizeof(int) * nbroom);
	ft_bzero(bfs->flow, nbroom * nbroom);
	bfs->pred = (int *)malloc(sizeof(int) * nbroom);
	ft_bzero(bfs->flow, nbroom * nbroom);
	bfs->queue = (int *)malloc(sizeof(int) * (nbroom + 2));
	ft_bzero(bfs->flow, nbroom * nbroom);
	if (!bfs->capacity
		|| !bfs->flow
		|| !bfs->color
		|| !bfs->pred
		|| !bfs->queue)
		error_malloc();
	ft_printf("initbfsqueu: %p\n", bfs->queue);
}
