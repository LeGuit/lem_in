#include "lem_in.h"

void				nb_path(t_data *data, t_path *path)
{
	int				i;

	i = 0;
	while (i < nbroom)
	{
		if (data->matrix[data->idstart][i] == 'X')
			path->nbstart++;
		if (data->matrix[data->idend][i] == 'X')
			path->nbend++;
		i++;
	}
	path->nbpath = MIN(nbstart, nbend);

}
