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
	ft_printf("%d\t%d\n",x, bfs->tail);
	bfs->queue[bfs->tail] = x;
	ft_printf("%d\n", bfs->tail);
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

int					b_f_s(int start, int target, t_bfs *bfs, t_data *data)
{
	int				it;
	int				k;

	bfs->head = 0;
	bfs->tail = 0;
	it = 0;
	ft_printf("YO %d\n", data->nbroom);
	ft_bzero(&bfs->color, data->nbroom * sizeof(int));
	enqueue(start, bfs);
	bfs->pred[start] = -1;
	while (bfs->head != bfs->tail)
	{
		k = dequeue(bfs);
		while (it < data->nbroom)
		{
			if (bfs->color[it] == WHITE && (bfs->capacity)[k][it] > 0)
			{
				enqueue(it, bfs);
				bfs->pred[it] = k;
			}
			it++;
		}
	}
	return (bfs->color[target] == BLACK);
}