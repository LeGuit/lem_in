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
	ft_putendl_fd("lem_in: wrong input", 2);
	ft_putendl_fd("usage: ./lem_in [file]", 2);
	exit(0);
}

void				error_open(void)
{
	ft_putendl_fd("lem_in: fail to open file", 2);
	exit(0);
}

void				error_malloc(void)
{
	ft_putendl_fd("lem_in: malloc error", 2);
	exit(0);
}