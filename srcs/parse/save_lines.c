/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:16:32 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:16:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define CAST(type, ptr)				((type)(ptr))

void				save_com(char *line, t_data *data)
{
	size_t			size;

	size = ft_strlen(line);
	data->com = (char *)malloc(sizeof(char) * (size + 1));
	if (!data->com)
		error_malloc();
	data->com[size] = 0;
	ft_strncpy(data->com, line, size);
}

void				save_ants(char *line, t_data *data)
{
	if (data->com)
		ants_comment(data);
	data->nbants = ft_atoi(line);
	return ;
}

void				save_rooms(char *line, t_data *data)
{
	int				i;
	t_room			r;

	r.id = data->nbroom;
	data->nbroom++;
	r.com = 0;
	i = 0;
	while (line[i] != ' ')
		i++;
	r.name = (char *)malloc(sizeof(char) * (i + 1));
	r.name[i] = 0;
	ft_strncpy(r.name, line, i);
	r.coord[0] = ft_atoi(&line[++i]);
	while (line[i] != ' ')
		i++;
	r.coord[1] = ft_atoi(&line[++i]);
	if (data->com)
		room_comment(data, &r);
	ft_vect_push_back(&data->anthill, &r);
}

void				init_matrix(char *line, t_data *data)
{
	int				i;

	data->matrix = (char **)malloc(data->nbroom * sizeof(char *));
	i = 0;
	while (i < data->nbroom)
	{
		data->matrix[i] = (char *)malloc(data->nbroom);
		ft_bzero(data->matrix[i], data->nbroom);
		i++;
	}
	data->state++;
	save_hubs(line, data);
}

void				save_hubs(char *line, t_data *data)
{
	int				x;
	int				y;
	size_t			i;
	char			*cursor;
	t_room			*r;

	x = -1;
	y = -1;
	cursor = ft_strchr(line, '-');
	i = 0;
	while (i < data->anthill.size)
	{
		r = CAST(t_room *, ft_vect_at(&data->anthill, i));
		if (!ft_strncmp(r->name, line, cursor - line))
			x = r->id;
		if (!ft_strcmp(r->name, cursor + 1))
			y = r->id;
		i++;
	}
	if (x == -1 || y == -1)
		error_hubs();
	data->matrix[x][y] = 'X';
	data->matrix[y][x] = 'X';
}
