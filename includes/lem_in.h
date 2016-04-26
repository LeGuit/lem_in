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

# define WHITE		0
# define GREY		1
# define BLACK		2
# define INT_MAX	2147483647
# define R_IN(i)	(2 * (i))
# define R_OUT(i)	(2 * (i) + 1)

typedef struct		s_onepath
{
	int				*path;
	int				size;
}					t_onepath;

typedef struct		s_ant
{
	t_onepath		*path;
	int				antid;
	int				move;
	int				status;
}					t_ant;

typedef struct		s_allpaths
{
	int				maxflow;
	int				idmin;
	int				sizemin;
	t_vect			paths;
}					t_allpaths;

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
	t_vect			input;
	int				*matrix;
	char			*com;
	int				nbroom;
	int				nbpath;
	int				nbants;
	char			*antcom;
	int				state;
	int				idstart;
	int				idend;
}					t_data;

typedef struct		s_bfs
{
	int				*capacity;
	int				*flow;
	int				*color;
	int				*pred;
	int				*queue;
	int				head;
	int				tail;
	int				size;
}					t_bfs;

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
void				get_file(t_data *data);
int					b_f_s(int start, int target, t_bfs *bfs);
void				init_bfs(t_bfs *bfs, t_data *d);
void				free_bfs(t_bfs *b);
int					max_flow(int source, int sink, t_bfs *bfs, t_allpaths *ap);
void				save_path(int start, int end, int *pred, t_allpaths *ap);

/*
** ANTS INVASION
*/
void				ants_invasion(t_allpaths *p, t_data *d);
void				print_ant(t_ant *a, t_data *d);
/*
** DEBUG
*/
void				print_input(char **v);
void				print_data(t_data *data);
void				print_room(t_room *r);
void				print_matrix(int *tab, int size);
void				print_anthill(t_data *d);
void				print_bfs(int target, int start, t_bfs *b);
void				print_path(t_onepath *p);
void				print_ants_array(t_ant *ants_array, int size);

#endif
