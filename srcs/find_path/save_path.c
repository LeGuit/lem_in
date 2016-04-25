/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:01:42 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/04/25 16:01:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			size_path(int start, int end, int *pred)
{
	int				size;
	int				i;

	size = 0;
	i = end;
	while (i != start)
	{
		i = pred[i];
		size++;
	}
	size++;
	ft_printf("size path: %d\n", (size + 2) / 2);
	return ((size + 2) / 2);
}

static void			copy_path(t_onepath *p, int *pred, int start, int end)
{
	int				i;
	int				j;

	p->path[0] = (start - 1) / 2;
	p->path[p->size - 1] = end / 2;
	i = p->size - 2;
	j = end;
	while (i > 0)
	{
		p->path[i] = pred[j] / 2;
		j = pred[pred[j]];
		i--;
	}
	while (i < p->size - 1)
	{
		ft_printf("%d -> ", p->path[i]);
		i++;
	}
	ft_printf("%d\n", p->path[p->size - 1]);
}

void				save_path(int start, int end, int *pred, t_allpaths *ap)
{
	t_onepath		onepath;

	(void)ap;
	onepath.size = size_path(start, end, pred);
	onepath.path = MALLOC(int, onepath.size);
	copy_path(&onepath, pred, start, end);
}
