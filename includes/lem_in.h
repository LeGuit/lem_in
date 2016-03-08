/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:32:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 15:32:48 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_H
# define _LEM_IN_H

# include "libft.h"

typedef struct		s_path
{
	int				nbstart;
	int				nbend;
	int				nbpath;
	int				**hubs;//hun[x][0] = size path
}					t_path;

typedef struct		s_room
{
	char			*name;
	char			*com;
	int				id;
	int				coord[2];
}					t_room;

typedef struct		s_data
{
	t_vect			anthill;
	char			**matrix;
	char			*com;
	int				nbroom;
	int				nbpath;
	int				nbants;
	char			*antcom;
	int				state;
	int				idstart;
	int				idend;
}					t_data;

/*
** PARSING
*/
typedef void		(*t_get_fct)(char *line, t_data *data);
typedef int			(*t_check_fct)(char *line);

int					check_com(char *line);
int					check_ants(char *line);
int					check_rooms(char *line);
int					check_hubs(char *line);
int					check_nothing(char *line);

void				save_com(char *line, t_data *data);
void				save_ants(char *line, t_data *data);
void				save_rooms(char *line, t_data *data);
void				save_hubs(char *line, t_data *data);

void				ants_comment(t_data *data);
void				room_comment(t_data *data, t_room *r);
void				init_matrix(char *line, t_data *data);
void				save_hubs(char *line, t_data *data);

void				get_file(char *file, t_data *data);

/*
** ERROR
*/
void				error_input(void);
void				error_open(void);
void				error_malloc(void);
void				error_hubs(void);


/*
** PATH FINDING
*/
void				path_finding(t_data *data);
void				nb_path(t_data *data, t_path *path);

/*
** DEBUG
*/
void				print_data(t_data *data);
void				print_room(t_room *r);
void				print_matrix(t_data *data);

#endif
