/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/25 17:13:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_rooms(t_map *map)
{
	t_room	*cpy;

	cpy = map->head;
	//if (map->head)
	//	ft_printf("map->head->id: %s\n", map->head->id);
	while (cpy)
	{
		ft_printf("id: %s\n", cpy->id);
		ft_printf("x: %d\n", cpy->x);
		ft_printf("y: %d\n", cpy->y);
		if (cpy->next)
			ft_printf("___\n");
		cpy = cpy->next;
	}
}

int		main(void)
{
	t_map	*map;

	ft_map_init(&map);
	ft_reader(&map);
	read_rooms(map);
	ft_map_del(&map);
	return (EXIT_SUCCESS);
}
