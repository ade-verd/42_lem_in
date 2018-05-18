/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/18 16:57:03 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_rooms(t_map *map)
{
	t_room	*cpy;

	cpy = map->head;
	ft_printf("AP:\t%p\n", cpy);
	while (cpy)
	{
		ft_printf("id: %s", cpy->id);
		ft_printf("x: %d", cpy->x);
		ft_printf("y: %d", cpy->y);
		cpy = cpy->next;
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_map	*map;

	i = 1;
	if (ac > 1)
	{
		ft_map_init(&map);
		ft_printf("head:\t%p\n", map->head);
		ft_add_room(&map, av);
		ft_printf("head:\t%p\n", map->head);
		read_rooms(map);
		ft_map_del(&map);
	}
	else
		ft_printf("no arg\n");
	return (EXIT_SUCCESS);
}
