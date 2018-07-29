/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_links.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:37:16 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 18:24:00 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** static t_link	*ft_create_link(t_map **map, char **info, int rev)
** Creates link (memory allocation)
*/

static t_link	*ft_create_link(t_map **map, char **info, int rev)
{
	t_link	*new;
	t_link	*last;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	new->from = rev ? get_room_ptr(map, info[1]) : get_room_ptr(map, info[0]);
	new->to = rev ? get_room_ptr(map, info[0]) : get_room_ptr(map, info[1]);
	new->next = NULL;
	last = new->from->link;
	while (last && last->next)
		last = last->next;
	if (last)
	{
		new->prev = last;
		last->next = new;
	}
	else
	{
		new->prev = NULL;
		new->from->link = new;
	}
	return (new);
}

/*
** void	ft_add_link(t_map **map, char **link_info)
** Adds link (main function)
*/

void			ft_add_link(t_map **map, char **link_info)
{
	ft_create_link(map, link_info, 0);
	ft_create_link(map, link_info, REVERSE);
	ft_freetab_strsplit(link_info);
}

/*
** void	ft_links_del(t_link **links)
** Deletes links
*/

void			ft_links_del(t_link **links)
{
	t_link	*cpy;

	while (*links)
	{
		cpy = *links;
		*links = (*links)->next;
		ft_memdel((void**)&cpy);
	}
}
