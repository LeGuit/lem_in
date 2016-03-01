#include "lem_in.h"

void				save_com(char *line, t_data *data)
{
	size_t			size;

	size = ft_strlen(line);
	data->com = (char *)malloc(sizeof(char) * size + 1);
	if (!data->com)
		error_malloc();
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

	r.spec = 0;
	data->nbroom++;
	if (data->com)
		room_comment(data, &r);
	while (line[i] != ' ')
		i++;
	line[i] = 0;
	r.name = ft_strdup(line);
	r.coord[0] = ft_atoi(&line[++i]);
	while (line[i] != ' ')
		i++;
	r.coord[1] = ft_atoi(&line[++i]);
}

void				init_matrix(char *line, t_data *data)
{
	int				i;

	(void)line;
	data->matrix = ft_memalloc(data->nbroom);
	i = 0;
	while (i < data->nbroom)
	{
		matrix[i] = ft_memalloc(data->nbroom);
		i++;
	}
}

void				save_hubs(char *line, t_data *data)
{
	int				x;
	int				y;
	char			*tmp;

	x = ft_atoi(line);
	tmp = ft_strchr(line, '-') + 1;
	y = ft_atoi(tmp);
	data->matrix[x][y] = 1;
}
