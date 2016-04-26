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
		if (path->size < p->minpath.size)
		{
			p->minpath.size = path->size;
			ft_memcpy(p->minpath.path, path->path, path->size * sizeof(int));
		}
		i++;
	}
}

void				path_finding(t_data *d)
{
	t_allpaths		allpaths;
	t_bfs			bfs;

	allpaths.paths = VECT_INI(t_onepath);
	allpaths.minpath.size = d->nbroom;
	init_bfs(&bfs, d);
	// ft_printf("\n---- START MAXFLOW ----\n");
	allpaths.maxflow = max_flow(R_OUT(d->idstart), R_IN(d->idend), &bfs,
								&allpaths);
	free_bfs(&bfs);
	ft_printf("\n---- PRINT PATH FETCHED ----\n");
	ft_vect_print(&allpaths.paths, print_path);
	ft_printf("ffaflow: %d\n", allpaths.maxflow);
	get_min_path(&allpaths);
	ft_printf("\n---- PRINT MIN PATH FOUND ----\n");
	print_path(&allpaths.minpath);
	// ants_invasion(&allpaths, d);
}
