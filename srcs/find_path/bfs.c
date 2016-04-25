/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:47:41 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/23 11:48:04 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			enqueue(int x, t_bfs *bfs)
{
	bfs->queue[bfs->tail] = x;
	bfs->tail++;
	bfs->color[x] = GREY;
}

static int			dequeue(t_bfs *bfs)
{
	int				x;

	x = bfs->queue[bfs->head];
	bfs->head++;
	bfs->color[x] = BLACK;
	return (x);
}

static void			init_color(int *c, int size)
{
	int				it;

	it = 0;
	while (it < size)
	{
		c[it] = WHITE;
		it++;
	}
}

int					b_f_s(int start, int target, t_bfs *b)
{
	int				i;
	int				j;
	int				size;

	b->head = 0;
	b->tail = 0;
	size = b->size;
	init_color(b->color, size);
	enqueue(start, b);
	b->pred[start] = -1;
	while (b->head != b->tail)
	{
		i = dequeue(b);
		j = 0;
		while (j < size)
		{
			if (b->color[j] == WHITE
				&& (b->capacity[T(i, j, size)] - b->flow[T(i, j, size)]) > 0)
			{
				enqueue(j, b);
				b->pred[j] = i;
			}
			j++;
		}
	}
	print_bfs(start, target, b);
	return (b->color[target] == BLACK);
}
