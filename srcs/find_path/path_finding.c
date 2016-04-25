/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:42:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/23 11:42:22 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static void			init_path(t_path *path, t_data *d)
// {
// 	int				j;
// 	int				p_start;
// 	int				p_end;

// 	p_start = 0;
// 	p_end = 0;
// 	j = 0;
// 	while (j < d->nbroom)
// 	{
// 		if (d->matrix[T(d->idstart, j, d->nbroom * 2)] == 1)
// 			p_start++;
// 		if (d->matrix[T(d->idend, j, d->nbroom * 2)] == 1)
// 			p_end++;
// 		j++;
// 	}
// 	path->maxflow = MIN(p_start, p_end);
// }

// static void			init_hubs(t_path *path, t_data *d)
// {
// 	int				i;

// 	path->hubs = (int *)malloc(sizeof(int) * path->maxflow * d->nbroom);
// 	if (!path->hubs)
// 		error_malloc();
// 	i = 0;
// 	while (i < path->maxflow * d->nbroom)
// 	{
// 		path->hubs[i] = -1;
// 		i++;
// 	}
// }

void				path_finding(t_data *d)
{
	t_allpaths		allpaths;
	t_bfs			bfs;

	allpaths.paths = VECT_INI(t_onepath);
	init_bfs(&bfs, d);
	ft_printf("\n---- START MAXFLOW ----\n");
	allpaths.maxflow = max_flow(R_OUT(d->idstart), R_IN(d->idend), &bfs,
								&allpaths);
	ft_printf("\n---- PRINT PATH FETCHED ----\n");
	ft_vect_print(&allpaths.paths, print_path);
	ft_printf("ffaflow: %d\n", allpaths.maxflow);
	exit(0);
	// nb_paths(d, &path);
	// init_hubs(&path, d);
}
