
#ifndef _LEM_IN_H
# define _LEM_IN_H

# include "libft.h"

typedef void		(*t_get_fct)(char *line, t_data *data);
typedef int			(*t_check_fct)(char *line);

typedef struct 		s_room
{
	char			*name;
	int				spec;//0 random, 1 start, -1 end
	int				coord[2];
}					t_room;

typedef struct		s_data
{
	t_vect			anthill;
	char			*com;
	int				nbroom;
	int				nbpath;
	int				nbants;
	int				com;
}					t_data;

int					check_com(char *line);
int					check_ants(char *line);
int					check_rooms(char *line);
int					check_hubs(char *line);

int					save_com(char *line, t_data *data);
int					save_ants(char *line, t_data *data);
int					save_rooms(char *line, t_data *data);
int					save_hubs(char *line, t_data *data);

#endif