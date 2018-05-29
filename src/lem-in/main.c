/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/29 11:34:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_links(t_room *current)
{
	t_link	*link;

	link = current->link;
	link ? ft_printf("links:\t") : ft_printf("links:\t(null)");
	while (link)
	{
		ft_printf("%s", link->to->id);
		if (link->next)
			ft_putstr(", ");	
		link = link->next;
	}
	ft_putchar('\n');
}

void	read_rooms(t_map *map)
{
	t_room	*cpy;

	cpy = map->head;
	while (cpy)
	{
		if (cpy == map->start)
			ft_putstr(F_GREEN);
		if (cpy == map->end)
			ft_putstr(F_RED);
		ft_printf("id:\t%s\n", cpy->id);
		ft_printf("x:\t%d\n", cpy->x);
		ft_printf("y:\t%d\n", cpy->y);
		read_links(cpy);
		if (cpy->next)
			ft_printf("%s___\n", F_NO);
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
