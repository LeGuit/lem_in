#include "lem_in.h"

static t_check_fct const	g_check_tab[5] =
{
	[0] = &check_com,
	[1] = &check_ants,
	[2] = &check_rooms,
	[3] = &check_hubs,
	[4] = &check_hubs
};

static t_get_fct const	g_get_info[4] =
{
	[0] = &save_com,
	[1] = &save_ants,
	[2] = &save_rooms,
	[3] = &init_matrix,
	[4] = &save_hubs
};

static int			check_func(char *line, t_data* data)
{
	if (g_check_tab[data->state](line)
		&& (ret = g_check_tab[data->state + 1](line))
	return (1);
	if (!ret)
		data->state++;//start like this
	g_get_info[data->state](line, data);
	return (0);
}

void				get_file(char *file, t_data *data)
{
	int				fd;
	char			*line;
	int				ret;

	state_parse = 1;//1 after nb ants etc
	if ((fd = open(file, O_RDONLY)) == -1)
		error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (g_check_tab[0])
			g_get_info[0](line, data);
		else if (check_func(line, data))
			break ;
		ft_printf("'debug' line: %s\n", line);
	}
	close(fd);
}