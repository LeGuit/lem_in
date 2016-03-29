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

static void			enqueue(int x, t_bfs *bfs, int *tail)
{
	bfs->queue[*tail] = x;
	(*tail)++;
	bfs->color[x] = GREY;
}

static int			dequeue(t_bfs *bfs, int *head)
{
	int				x;

	x = bfs->queue[*head];
	(*head)++;
	bfs->color[x] = BLACK;
	return (x);
}

int					b_f_s(int start, int target, t_bfs *bfs, t_data *data)
{
	int				head;
	int				tail;
	int				it;
	int				k;

	head = 0;
	tail = 0;
	it = 0;
	ft_bzero(bfs->color, data->nbroom);//bug
	ft_printf("YO");
	enqueue(start, bfs, &tail);
	bfs->pred[start] = -1;
	while (head != tail)
	{
		k = dequeue(bfs, &head);
		while (it < data->nbroom)
		{
			if (bfs->color[it] == WHITE && (bfs->capacity)[k][it] > 0)
			{
				enqueue(it, bfs, &tail);
				bfs->pred[it] = k;
			}
			it++;
		}
	}
	return (bfs->color[target] == BLACK);
}