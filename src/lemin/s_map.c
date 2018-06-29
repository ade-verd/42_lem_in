/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:30:07 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/29 18:47:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_map_init(t_map **map)
{
	if (!(*map = (t_map*)malloc(sizeof(t_map))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	(*map)->ants = 0;
	(*map)->lap = 0;
	(*map)->lapsmove = 0;
	(*map)->nb_start = 0;
	(*map)->nb_end = 0;
	(*map)->rooms = 0;
	(*map)->solutions = 0;
	(*map)->head = NULL;
	(*map)->ways = NULL;
	(*map)->start = NULL;
	(*map)->end = NULL;
	(*map)->lines = NULL;
	(*map)->command = 0;
	(*map)->option_f = 0;
	(*map)->fd = 0;
	(*map)->path = NULL;
}

void	ft_map_del(t_map **map)
{
	if ((*map)->path)
		ft_strdel(&(*map)->path);
	ft_ways_del(&(*map)->ways);
	ft_rooms_del(&(*map)->head);
	ft_lines_del((*map)->lines);
	if (*map)
		ft_memdel((void**)map);
}