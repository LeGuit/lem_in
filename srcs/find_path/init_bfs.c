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

static void				set_capacity(int *c, int nb)
{
	int					i;

	i = 0;
	while (i < nb * nb)
	{
		c[i] = 1;
		i++;
	}
}

void					init_bfs(t_bfs *b, int nbroom)
{
	b->capacity = (int *)malloc(sizeof(int) * nbroom * nbroom);
	set_capacity(b->capacity, nbroom);
	ft_printf("after memset %d\n",b->capacity[0]);
	b->flow = (int *)malloc(sizeof(int) * nbroom * nbroom);
	ft_bzero(b->flow, sizeof(int) * nbroom * nbroom);
	b->color = (int *)malloc(sizeof(int) * nbroom);
	ft_bzero(b->color, sizeof(int) * nbroom);
	b->pred = (int *)malloc(sizeof(int) * nbroom);
	ft_bzero(b->pred, sizeof(int) * nbroom);
	b->queue = (int *)malloc(sizeof(int) * (nbroom + 2));
	ft_bzero(b->queue, sizeof(int) * (nbroom + 2));
	if (!b->capacity
		|| !b->flow
		|| !b->color
		|| !b->pred
		|| !b->queue)
		error_malloc();
	ft_printf("init bqueu: %p\n", b->queue);
}
