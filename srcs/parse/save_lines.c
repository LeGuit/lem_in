#include "lem_in.h"

void				save_ants(char *line, t_data *data)
{
	data->nbants = ft_atoi(line);
	return ;
}

void				save_rooms(char *line, t_data *data)
{
	int				i;
	t_room			r;

	while (line[i] != ' ')
		i++;
	r.

}