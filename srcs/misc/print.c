/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:42:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/23 11:42:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_input(char **v)
{
	ft_printf("%s\n", *v);
}

void				print_path(t_onepath *p)
{
	int				i;

	ft_printf("size of path: %d\n", p->size);
	i = 0;
	while (i < p->size - 1)
	{
		ft_printf("%d -> ", p->path[i]);
		i++;
	}
	ft_printf("%d\n", p->path[p->size - 1]);
}
