/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:30:43 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/24 17:30:39 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	fdprint_links(t_room *current, int fd)
{
	t_link	*link;

	link = current->link;
	while (link)
	{
		ft_dprintf(fd, "%s; ", link->to->id);
		link = link->next;
	}
}

static void	fdprint_rooms_links(t_map *map, int fd)
{
	t_room	*cpy;

	cpy = map->head;
	while (cpy)
	{
		if (!cpy->link)
			ft_dprintf(fd, "\t%s;\n", cpy->id);
		else
		{
			ft_dprintf(fd, "\t%s -- { ", cpy->id);
			fdprint_links(cpy, fd);
			ft_putstr_fd("}\n", fd);
		}
		cpy = cpy->next;
	}
}

void	ft_create_graphfile(t_map *map)
{
	int		fd;

	if ((fd = ft_open_fd(DOTFILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		ft_error(&map, "ft_create_graphfile", 0);
	ft_putstr_fd("graph G {\n", fd);
	fdprint_rooms_links(map, fd);
	ft_putstr_fd("}\n", fd);
	if ((ft_close_fd(fd)) == -1)
		ft_error(&map, "ft_create_graphfile", 0);
	if ((execlp ("sh", "sh", GRAPH_SH, DOTFILE, PNGFILE, NULL)) == -1)
	{
		ft_dprintf(2, "Graphviz execution failed\n");
		ft_dprintf(2, "Try:\tdot -Tpng %s -o %s\n", DOTFILE, PNGFILE);
	}
}