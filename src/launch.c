/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:28:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 18:37:25 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** static void	status_ants(t_map *map)
** Displays status
*/

static void	status_ants(t_map *map)
{
	if (map->flags & FLAG_STATUS)
	{
		if (!(map->flags & FLAG_MUTE))
			ft_putchar('\n');
		ft_printf("Initial number of ants: \t%d\n", map->ants);
		ft_printf("Number of ants arrived: \t%d\n", map->nb_end);
		ft_printf("Number of remaining ants: \t%d\n", map->nb_start);
		if (map->ants == map->nb_end && !map->nb_start)
			ft_printf("OK\n");
		else
			ft_printf("ERROR\n");
	}
}

/*
** void	launch_ants(t_map *map)
** Launches ant(s) from start to first room of selected ways
*/

void		launch_ants(t_map *map)
{
	t_way	*ways;

	ways = map->ways;
	while (ways && ways->rooms && map->nb_start)
	{
		if (ways->rooms[0] && ways->select)
		{
			if (ways->rooms[1] && ways->rooms[1]->ant_id == 0)
			{
				ways->rooms[0]->ant_id = map->ants - map->nb_start + 1;
				move_ant(map, ways->rooms[0], ways->rooms[1]);
				map->nb_start--;
			}
		}
		ways = ways->next;
	}
}

/*
** void	solve(t_map *map)
** Solves map. Moves every ants and then launches ants.
*/

void		solve(t_map *map)
{
	map->nb_start = map->ants;
	while (map->nb_end < map->ants)
	{
		map->lap++;
		map->lapsmove = 0;
		move_all(map);
		if (map->nb_start)
			launch_ants(map);
		if (!(map->flags & FLAG_MUTE))
			ft_putchar('\n');
	}
	status_ants(map);
}
