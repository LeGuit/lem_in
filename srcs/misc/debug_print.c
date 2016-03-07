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
	ft_printf("name: %s\nx: %d\ty: %d\ncom: %s\n",
		r->name, r->coord[0], r->coord[1], r->com);
}

void				print_data(t_data *data)
{
	ft_printf("\nants: %d\tnbrooms: %d\tnbpath: %d\n",
		data->nbants, data->nbroom, data->nbpath);
	ft_printf("ROOMS:\n");
	ft_vect_print(&data->anthill, print_room);
}