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

static void			init_path(t_path *path, t_data *d)
{
	int				j;
	int				p_start;
	int				p_end;

	p_start = 0;
	p_end = 0;
	j = 0;
	while (j < d->nbroom)
	{
		if (d->matrix[T(d->idstart, j, d->nbroom * 2)] == 1)
			p_start++;
		if (d->matrix[T(d->idend, j, d->nbroom * 2)] == 1)
			p_end++;
		j++;
	}
	path->maxflow = MIN(p_start, p_end);
}

static void			init_hubs(t_path *path, t_data *d)
{
	int				i;

	path->hubs = (int *)malloc(sizeof(int) * path->maxflow * d->nbroom);
	if (!path->hubs)
		error_malloc();
	i = 0;
	while (i < path->maxflow * d->nbroom)
	{
		path->hubs[i] = -1;
		i++;
	}
}

void				path_finding(t_data *d)
{
	t_path			path;
	t_bfs			bfs;
	// int				flow;

	init_path(&path, d);
	ft_printf("maxflow: %d\n", path.maxflow);
	init_bfs(&bfs, d);
	ft_printf("\nSTART MAXFLOW\n");
	ft_printf("start: %d\t end: %d\n", d->idstart, d->idend);
	b_f_s(R_IN(d->idstart), R_IN(d->idend), &bfs);
	// flow = max_flow(d->idstart, d->idend, &bfs, d);
	// ft_printf("ffaflow: %d\n", flow);
	exit(0);
	// nb_paths(d, &path);
	init_hubs(&path, d);
}
