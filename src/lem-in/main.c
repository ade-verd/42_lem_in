/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/23 19:46:44 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_rooms(t_map *map)
{
	t_room	*cpy;

	cpy = map->head;
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
