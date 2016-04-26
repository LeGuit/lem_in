/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:15:22 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:16:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

static t_check_fct const	g_check_tab[] =
{
	[0] = &check_com,
	[1] = &check_ants,
	[2] = &check_rooms,
	[3] = &check_hubs,
	[4] = &check_nothing
};

static t_get_fct const		g_get_info[] =
{
	[0] = &save_com,
	[1] = &save_ants,
	[2] = &save_rooms,
	[3] = &init_matrix,
	[4] = &save_hubs
};

static int			check_input(t_data *d)
{
	if (d->nbroom == 0)
		ft_putendl_fd("ERROR: lem-in: No room in the map !", 2);
	else if (d->nbpath == 0)
		ft_putendl_fd("ERROR: lem-in: No path in the map !", 2);
	else if (d->nbants == 0)
		ft_putendl_fd("ERROR: lem-in: No ants in the map !", 2);
	else if (d->idstart == -1)
		ft_putendl_fd("ERROR: lem-in: No start in the map !", 2);
	else if (d->idend == -1)
		ft_putendl_fd("ERROR: lem-in: No end in the map !", 2);
	else
		return (0);
	return (1);
}

static int			check_func(char *line, t_data *data)
{
	int				ret;

	ret = 1;
	if (g_check_tab[data->state](line)
		&& (ret = g_check_tab[data->state + 1](line)))
		return (1);
	if (!ret)
		data->state++;
	g_get_info[data->state](line, data);
	return (0);
}

static void			save_input(char *l, t_data *data)
{
	char			*savel;

	savel = ft_strdup(l);
	if (!savel)
		error_malloc();
	ft_vect_push_back(&data->input, &savel);
}

void				get_file(t_data *data)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		save_input(line, data);
		if (g_check_tab[0](line))
			g_get_info[0](line, data);
		else if (check_func(line, data))
			break ;
		free(line);
	}
	if (check_input(data) || ret != 0)
		exit(0);
}
