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
#define T(i,j,off)	((j) + (i * off))

static void			enqueue(int x, t_bfs *bfs)
{
	ft_printf("enqueue\n");
	bfs->queue[bfs->tail] = x;
	bfs->tail++;
	bfs->color[x] = GREY;
}

static int			dequeue(t_bfs *bfs)
{
	int				x;

	ft_printf("dequeue\n");
	x = bfs->queue[bfs->head];
	bfs->head++;
	bfs->color[x] = BLACK;
	return (x);
}

static void			init_color(int *c, int nbroom)
{
	int				it;

	it = 0;
	while (it < nbroom)
	{
		c[it] = WHITE;
		it++;
	}
}

int					b_f_s(int start, int target, t_bfs *b, t_data *d)
{
	int				i;
	int				j;

	b->head = 0;
	b->tail = 0;
	init_color(b->color, d->nbroom);
	enqueue(start, b);
	ft_printf("FIRST ENQUEUE PASS\n");
	b->pred[start] = -1;
	while (b->head != b->tail)
	{
		i = dequeue(b);
		j = 0;
		while (j < d->nbroom)
		{
			ft_printf("cap: %d, flow: %d\n", b->capacity[T(i, j, d->nbroom)], b->flow[T(i, j, d->nbroom)]);
			if (b->color[j] == WHITE
				&& (b->capacity[T(i, j, d->nbroom)] - b->flow[T(i, j, d->nbroom)]) > 0)
			{
				enqueue(j, b);
				b->pred[j] = i;
			}
			j++;
		}
	}
	i = 0;
	while (i < d->nbroom)
		{
			ft_printf("pred[%d]: %d\n", i, b->pred[i]);
			i++;
		}
	i = target;
	while (i != start)
	{
		ft_printf("%d <- ", i);
		i = b->pred[i];
	}
	ft_printf("%d\n", start);
	// exit (0);
	return (b->color[target] == BLACK);
}
