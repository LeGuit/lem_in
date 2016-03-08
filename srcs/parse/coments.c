/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coments.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:15:18 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:15:19 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ants_comment(t_data *data)
{
	data->antcom = ft_strdup(data->com);
	free(data->com);
	data->com = 0;
}

void				room_comment(t_data *data, t_room *r)
{
	if (ft_strcmp(data->com, "##start") == 0)
		data->idstart = r->id;
	else if (ft_strcmp(data->com, "##end") == 0)
		data->idend = r->id;
	r->com = ft_strdup(data->com);
	free(data->com);
	data->com = 0;
}
