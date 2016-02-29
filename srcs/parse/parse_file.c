#include "lem-in"




void			get_file(char *file, t_data *data)
{
	int			fd;
	char		*line;
	int			ret;

	if ((fd = open(file, O_RDONLY)) == -1)
		error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((ret = check_line(line, data)))
			break ;//start like this
		get_info(line, data);
		ft_printf("'debug' line: %s\n", line);
	}
	close(fd);
}