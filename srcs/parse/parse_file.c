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

void				get_file(t_data *data)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (g_check_tab[0](line))
			g_get_info[0](line, data);
		else if (check_func(line, data))
			break ;
		ft_printf("'debug' line: %s\n", line);
		line = 0;
	}
}
