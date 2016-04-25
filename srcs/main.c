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
	data->input = VECT_INI(char *);
}

int					main(void)
{
	t_data			data;

	init_data(&data);
	get_file(&data);
	// print_data(&data);
	path_finding(&data);
	while(1)
		;
	return (0);
}
