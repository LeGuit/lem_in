/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:14:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:14:10 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				error_input(void)
{
	ft_putendl_fd("lem-in: wrong input", 2);
	ft_putendl_fd("usage: ./lem-in < [file]", 2);
	exit(0);
}

void				error_open(void)
{
	ft_putendl_fd("lem-in: fail to open file", 2);
	exit(0);
}

void				error_malloc(void)
{
	ft_putendl_fd("lem-in: malloc error", 2);
	exit(0);
}

void				error_hubs(void)
{
	ft_putendl_fd("lem-in: wrong hub name", 2);
}
