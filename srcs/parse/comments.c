#include "lem_in.h"

void				ants_comment(t_data *data)
{
	data->ant_com = ft_strdup(data->com);
	free(data->com);
}

void				room_comment(t_data *data, t_room *r)
{
	if (ft_strcmp(data->com, "##start") == 0)
		r.spec = 1;
	else if (ft_strcmp(data->com, "##end") == 0)
		r.spec = -1;
	else
		r.com = ft_strdup(data->com);
	free(data->com);
}