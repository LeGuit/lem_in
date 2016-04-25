/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:29:49 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:29:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define CAST(type, ptr)				((type)(ptr))

void				print_room(t_room *r)
{
	ft_printf("\tname: %s\n\tx: %d\ty: %d\n\tcom: %s\tid: %d\n",
		r->name, r->coord[0], r->coord[1], r->com, r->id);
}

void				print_anthill(t_data *d)
{
	int				i;
	int				j;
	t_room			*r;

	i = 0;
	while (i < d->nbroom)
	{
		r = CAST(t_room *, ft_vect_at(&d->anthill, i));
		ft_printf("%s\t", r->name);
		j = 0;
		while (j < d->nbroom)
		{
			if (!d->matrix[T(R_OUT(i), R_IN(j), d->nbroom * 2)])
				ft_printf(". ");
			else
				ft_printf("X ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void				print_matrix(int *tab, int size)
{
	int				i;
	int				j;

	i = 0;
	while (i < size)
	{
		ft_printf("%s\t", i % 2 ? "OUT\t" : "IN\t");
		j = 0;
		while (j < size)
		{
			ft_printf("%d ", tab[T(i, j, size)]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void				print_data(t_data *d)
{
	ft_printf("\nants: %d\tnbrooms: %d\tnbpath: %d\n",
		d->nbants, d->nbroom, d->nbpath);
	ft_printf("ROOMS:\n");
	ft_vect_print(&d->anthill, print_room);
	ft_printf("MATRIX:\n");
	print_anthill(d);
}

void				print_bfs(int start, int target, t_bfs *b)
{
	int				i;

	ft_printf("start: %d\t end: %d\n", start / 2, target / 2);
	i = target;
	while (i != start)
	{
		ft_printf("%d <- ", i / 2);
		i = b->pred[i];
	}
	ft_printf("%d\n", start / 2);
}
