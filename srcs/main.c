/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:05:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:06:11 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			init_data(t_data *data)
{
	data->state = 1;
	data->nbpath = 0;
	data->nbroom = 0;
	data->com = 0;
	data->anthill = VECT_INI(t_room);
}

int					main(int ac, char **av)
{
	t_data			data;

	if (ac != 2)
		error_input();
	init_data(&data);
	get_file(av[1], &data);
	print_data(&data);
	// path_finding(&data);
	return (0);
}
