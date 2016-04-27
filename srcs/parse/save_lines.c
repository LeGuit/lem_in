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

	if (line[1] != '#')
		return ;
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

void				init_matrix(char *line, t_data *d)
{
	int				i;

	d->matrix = MALLOC(int, (d->nbroom * d->nbroom) * 4);
	if (!d->matrix)
		error_malloc();
	ft_bzero(d->matrix, (d->nbroom * d->nbroom * 4) * sizeof(int));
	d->state++;
	i = 0;
	while (i < d->nbroom)
	{
		d->matrix[T(R_IN(i), R_OUT(i), d->nbroom * 2)] = 1;
		i++;
	}
	save_hubs(line, d);
}

void				save_hubs(char *line, t_data *d)
{
	int				i;
	int				j;
	size_t			size;
	char			*cursor;
	t_room			*r;

	i = -1;
	j = -1;
	cursor = ft_strchr(line, '-');
	size = 0;
	d->nbpath++;
	while (size < d->anthill.size)
	{
		r = CAST(t_room *, ft_vect_at(&d->anthill, size));
		if (!ft_strncmp(r->name, line, cursor - line))
			i = r->id;
		if (!ft_strcmp(r->name, cursor + 1))
			j = r->id;
		size++;
	}
	if (i == -1 || j == -1)
		error_hubs();
	d->matrix[T(R_OUT(i), R_IN(j), d->nbroom * 2)] = 1;
	d->matrix[T(R_OUT(j), R_IN(i), d->nbroom * 2)] = 1;
}
