/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:30:07 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/17 19:13:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_map	ft_map_init(void)
{
	t_map	map;

	map.ants = 0;
	map.head = NULL;
	map.start = NULL;
	map.end = NULL;
	return (map);
}

void	ft_add_room(t_map map, char	**room_info)
{
	


}

t_room	*ft_create_room(t_room *current, char *id, int x, int y)
{
	t_room	new;

	new.id = id;
	new.x = x;
	new.y = y;
	new.ants = 0;
	new.link = NULL;
	new.next = NULL;
	new.prev = current;
	current->prev = &new;
}