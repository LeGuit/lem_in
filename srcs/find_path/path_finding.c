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

void				path_finding(t_data *d)
{
	t_allpaths		allpaths;
	t_bfs			bfs;

	allpaths.paths = VECT_INI(t_onepath);
	init_bfs(&bfs, d);
	// ft_printf("\n---- START MAXFLOW ----\n");
	allpaths.maxflow = max_flow(R_OUT(d->idstart), R_IN(d->idend), &bfs,
								&allpaths);
	ft_printf("\n---- PRINT PATH FETCHED ----\n");
	ft_vect_print(&allpaths.paths, print_path);
	ft_printf("ffaflow: %d\n", allpaths.maxflow);
	exit(0);
	// nb_paths(d, &path);
	// init_hubs(&path, d);
}
