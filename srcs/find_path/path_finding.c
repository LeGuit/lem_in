#include "lem_in.h"

static void			init_path(t_path *path)
{
	path->nbstart = 0;
	path->nbend = 0;
	path->nbpath = 0;
}

static void			init_hubs(t_path *path, t_data *data)
{
	int				i;

	path->hubs = (int **)malloc(sizeof(int) * path->nbpath);
	if (!path->hubs)
		error_malloc();
	i = 0;
	while (i < path->nbpath)
	{
		path->hubs[i] = (int *)malloc(sizeof(int) * data->nbroom);
		if (!path->hubs[i])
			error_malloc();
		i++;
	}
}

void				path_finding(t_data *data)
{
	t_path			path;

	init_path(&path);
	nb_paths(data, &path);
	init_hubs(&path, data);
}