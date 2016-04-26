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
#define CAST(type, ptr)				((type)(ptr))

void				path_finding(t_data *d)
{
	t_allpaths		allpaths;
	t_bfs			bfs;

	allpaths.paths = VECT_INI(t_onepath);
	allpaths.idmin = 0;
	allpaths.sizemin = d->nbroom;
	init_bfs(&bfs, d);
	allpaths.maxflow = max_flow(R_OUT(d->idstart), R_IN(d->idend), &bfs,
								&allpaths);
	free_bfs(&bfs);
	if (allpaths.maxflow == 0)
	{
		ft_putendl_fd("ERROR: lem-in: No path from start to end", 2);
		return ;
	}
	ft_printf("\n---- PRINT PATH FETCHED ----\n");
	ft_vect_print(&allpaths.paths, print_path);
	ft_printf("ffaflow: %d\n", allpaths.maxflow);
	ants_invasion(&allpaths, d);
}
