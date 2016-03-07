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

void				print_room(t_room *r)
{
	ft_printf("\tname: %s\n\tx: %d\ty: %d\n\tcom: %s\tspec: %d\tid: %d\n",
		r->name, r->coord[0], r->coord[1], r->com, r->spec, r->id);
}

void				print_matrix(t_data *data)
{
	int				i;
	int				j;

	i = 0;
	while (i < data->nbroom)
	{
		j = 0;
		while (j < data->nbroom)
		{
			if (!data->matrix[i][j])
				ft_printf(". ");
			else
				ft_printf("X ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void				print_data(t_data *data)
{
	ft_printf("\nants: %d\tnbrooms: %d\tnbpath: %d\n",
		data->nbants, data->nbroom, data->nbpath);
	ft_printf("ROOMS:\n");
	ft_vect_print(&data->anthill, print_room);
	ft_printf("MATRIX:\n");
	print_matrix(data);
}
