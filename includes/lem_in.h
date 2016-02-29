
#ifndef _LEM_IN_H
# define _LEM_IN_H

# include "libft.h"

typedef int			(*t_get_fct)(char *line, t_data *data);
typedef int			(*t_check_fct)(char *line);

typedef struct 		s_room
{
	int				coord[2];
	int				spec;//0 random, 1 start, -1 end
}					t_room;

typedef struct		s_data
{
	t_vect			anthill;
	int				nbroom;
	int				nbpath;
	int				nbants;
}					t_data;

#endif