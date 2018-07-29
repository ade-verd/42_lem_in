/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:31:13 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/26 18:44:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_command_start(t_map *map, t_room *new)
{
	if (!map->start)
		map->start = new;
	else
		ft_error(&map, "Multiple start", 0);
}

static void		ft_command_end(t_map *map, t_room *new)
{
	if (!map->end)
		map->end = new;
	else
		ft_error(&map, "Multiple end", 0);
}

void			ft_command(t_map *map, t_room *new)
{
	if (map->command == CMD_START)
		ft_command_start(map, new);
	else if (map->command == CMD_END)
		ft_command_end(map, new);
	map->command = 0;
}
