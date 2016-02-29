#include "lem_in.h"

int					check_com(char *line)
{
	if (line[0] != '#')
		return (0);
	if (line[1] == '#')
		return (0);
	return (1);
}

int					check_ants(char *line)
{
	int				i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int					check_rooms(char *line)
{
	char			*tmp;

	if (line[0] == 'L' || line[0] == #)
		return (1);
	if (!(tmp = ft_strchr(line, ' ')))
		return (1);
	while (*(tmp + 1) != ' ' && *tmp)
	{
		if (!ft_isdigit(*(tmp + 1)))
			return (1);
			tmp++;
	}
	if (!tmp)
		return (1);
	while (*(tmp + 1) != ' ' && *tmp)
	{
		if (!ft_isdigit(*(tmp + 1)))
			return (1);
			tmp++;
	}
	return (0);
}

int					check_hubs(char *line)
{
	int				i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != '-')
		return (1);
	i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (1);
	return (0);
}
