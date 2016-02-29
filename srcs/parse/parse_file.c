#include "lem-in"

static t_funct const	g_check_tab[3] =
{
	[0] = &check_ants,
	[1] = &check_rooms,
	[2] = &check_hubs,
	[3] = &check_hubs
};

static t_funct const	g_get_info[3] =
{
	[0] = &get_ants,
	[1] = &get_rooms,
	[2] = &get_hubs
};


void			get_file(char *file, t_data *data)
{
	int			fd;
	char		*line;
	int			ret;
	int			state_parse;

	state_parse = 0;//1 after nb ants etc
	if ((fd = open(file, O_RDONLY)) == -1)
		error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (g_check_tab[state_parse](line, data))
			&& (ret = g_check_tab[state_parse + 1](line, data)))
		{
			error();
			break ;
		}	
		if (!ret)
			state_parse++;//start like this
		g_get_info[state_parse](line, data);
		ft_printf("'debug' line: %s\n", line);
	}
	close(fd);
}