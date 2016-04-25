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

void					init_bfs(t_bfs *b, t_data *d)
{
	int					size;

	size = d->nbroom * 2;
	if (!(b->capacity = MALLOC(int, size * size))
		|| !(b->flow = MALLOC(int, size * size))
		|| !(b->color = MALLOC(int, size))
		|| !(b->pred = MALLOC(int, size))
		|| !(b->queue = MALLOC(int, size + 2)))
		error_malloc();
	ft_memcpy(b->capacity, d->matrix, size * size * sizeof(int));
	ft_bzero(b->flow, sizeof(int) * size * size);
	ft_bzero(b->color, sizeof(int) * size);
	ft_bzero(b->pred, sizeof(int) * size);
	ft_bzero(b->queue, sizeof(int) * size + 2);
	b->size = size;

}

void					free_bfs(t_bfs *b)
{
	free(b->capacity);
	free(b->flow);
	free(b->color);
	free(b->pred);
	free(b->queue);
}