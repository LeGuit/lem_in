#include "lem_in.h"

static void			init_path(t_path *path, t_data *data)
{
	int				i;
	int				p_start;
	int				p_end;

	p_start = 0;
	p_end = 0;
	i = 0;
	while (i < data->nbroom)
	{
		if (data->matrix[data->idstart][i] == 1)
			p_start++;
		if (data->matrix[data->idend][i] == 1)
			p_end++;
		i++;
	}
	path->nbpath = MIN(p_start, p_end);

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

	init_path(&path, data);
	ft_printf("nb_paths: %d\n", path.nbpath);
	exit(0);
	// nb_paths(data, &path);
	init_hubs(&path, data);
}