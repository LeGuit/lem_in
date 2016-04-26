/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:42:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/23 11:42:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define CAST(type, ptr)				((type)(ptr))

void				print_input(char **v)
{
	ft_printf("%s\n", *v);
}

void				print_path(t_onepath *p)
{
	int				i;

	ft_printf("size of path: %d\n", p->size);
	i = 0;
	while (i < p->size - 1)
	{
		ft_printf("%d -> ", p->path[i]);
		i++;
	}
	ft_printf("%d\n", p->path[p->size - 1]);
}

void				print_ants_array(t_ant *ants_array, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		ft_printf("antid: %d\n", ants_array[i].antid);
		print_path(ants_array[i].path);
		i++;
	}
}

void				print_ant(t_ant *a, t_data *d)
{
	t_room			*r;

	a->move++;
	r = CAST(t_room *, ft_vect_at(&d->anthill, a->path->path[a->move]));
	ft_printf("L%d-%s ", a->antid, r->name);
}