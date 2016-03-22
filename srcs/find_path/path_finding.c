#include "lem_in.h"

static void			init_path(t_path *path)
{
	path->nbpath = 0;
}

static void			init_hubs(t_path *path, t_data *data)
{
	int				i;

	path->hubs = (int *)malloc(sizeof(int) * path->nbpath * data->nbroom);
	if (!path->hubs)
		error_malloc();
	i = 0;
	while (i < path->nbpath * data->nbroom)
	{
		path->hubs[i] = -1;
		i++;
	}
}

void				path_finding(t_data *data)
{
	t_path			path;

	init_path(&path);
	// nb_paths(data, &path);
	init_hubs(&path, data);
}