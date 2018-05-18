/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:30:07 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/18 16:55:56 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_map_init(t_map **map)
{
	if (!(*map = (t_map*)malloc(sizeof(t_map))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	(*map)->ants = 0;
	(*map)->head = NULL;
	(*map)->start = NULL;
	(*map)->end = NULL;
}

void	ft_create_room(t_room **current, char **room_info)
{
	t_room	new;

	//ft_check_room_info();
	new.id = room_info[0];
	new.x = ft_atoi(room_info[1]);
	new.y = ft_atoi(room_info[2]);
	new.ants = 0;
	new.link = NULL;
	new.next = NULL;
	if (*current)
	{
		new.prev = *current;
		(*current)->next = &new;
	}
	else
	{
		new.prev = NULL;
		*current = &new;
	}
}

void	ft_add_room(t_map **map, char **room_info)
{
	t_room	*cpy;

	cpy = (*map)->head;
	ft_printf("head:\t%p\n", (*map)->head);
	while (cpy && cpy->next)
		cpy = cpy->next;
	ft_printf("AV:\t%p\n", cpy);
	ft_create_room(&cpy, room_info);
	ft_printf("AP:\t%p\n", cpy);
}

void	ft_map_del(t_map **map)
{
	if (*map)
		ft_memdel((void**)map);
}