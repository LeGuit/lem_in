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

static void			get_min_path(t_allpaths *p)
{
	size_t			i;
	t_onepath		*path;

	i = 0;
	while (i < p->paths.size)
	{
		path = CAST(t_onepath *, ft_vect_at(&p->paths, i));
		if (path->size < p->sizemin)
		{
			p->sizemin = path->size;
			p->idmin = i;
		}
		i++;
	}
}

void				path_finding(t_data *d)
{
	t_allpaths		allpaths;
	t_bfs			bfs;

	allpaths.paths = VECT_INI(t_onepath);
	allpaths.idmin = 0;
	allpaths.sizemin = d->nbroom;
	init_bfs(&bfs, d);
	// ft_printf("\n---- START MAXFLOW ----\n");
	allpaths.maxflow = max_flow(R_OUT(d->idstart), R_IN(d->idend), &bfs,
								&allpaths);
	free_bfs(&bfs);
	ft_printf("\n---- PRINT PATH FETCHED ----\n");
	ft_vect_print(&allpaths.paths, print_path);
	ft_printf("ffaflow: %d\n", allpaths.maxflow);
	get_min_path(&allpaths);
	ft_printf("\n---- PRINT ID PATH FOUND ----\n");
	ft_printf("sizemin: %d\tidmin: %d\n", allpaths.sizemin, allpaths.idmin);
	// ants_invasion(&allpaths, d);
}
