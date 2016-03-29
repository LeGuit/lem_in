/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:47:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 11:47:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			init_colorpred(int *array, int nbroom)
{
	array = (int *)malloc(sizeof(int) * nbroom);
	if (!array)
		error_malloc();
}

static void			init_caporflow(int **tab, int nbroom)
{
	int				it;

	tab = (int **)malloc(sizeof(int *) * nbroom);
	if (!tab)
		error_malloc();
	it = 0;
	while (it < nbroom)
	{
		tab[it] = (int *)malloc(sizeof(int) * nbroom);
		if (!tab[it])
			error_malloc();
		it++;
	}
}

void				init_bfs(t_bfs *bfs, t_data *data)
{
	init_caporflow(bfs->capacity, data->nbroom);
	init_caporflow(bfs->flow, data->nbroom);
	init_colorpred(bfs->color, data->nbroom);
	init_colorpred(bfs->pred, data->nbroom);
}