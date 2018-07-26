/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:30:43 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/26 14:30:54 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	link_is_on_way(t_map *map, t_room *r1, t_room *r2, int *par)
{
	t_way	*ways;
	int		i;

	ways = map->ways;
	while (ways && ways->rooms && ways->select)
	{
		i = 0;
		while (ways->rooms[i] && ways->rooms[i + 1])
		{
			if (ways->rooms[i] == r1 && ways->rooms[i + 1] == r2)
			{
				*par = ways->par;
				return (1);
			}
			if (ways->rooms[i] == r2 && ways->rooms[i + 1] == r1)
			{
				*par = ways->par;
				return (1);
			}
			i++;
		}
		ways = ways->next;
	}
	return (0);
}

static void	fdprint_links(t_map *map, t_room *current, int fd)
{
	t_link	*link;
	int		par;

	par = 0;
	link = current->link;
	while (link)
	{
		ft_dprintf(fd, "\t\"%s\" -- \"%s\"", current->id, link->to->id);
		if (link_is_on_way(map, current, link->to, &par))
		{
			ft_dprintf(fd, " [color=skyblue,penwidth=2.5]");
			if (current == map->start)
				ft_dprintf(fd, " [label=\"Par: %d\"]", par);
			else if (link->to == map->start)
				ft_dprintf(fd, " [style=invis]", par);
		}
		ft_putstr_fd(";\n", fd);
		link = link->next;
	}
}

static void	fdprint_rooms_links(t_map *map, int fd)
{
	t_room	*cpy;
	char	*label;

	cpy = map->head;
	while (cpy)
	{
		if (cpy == map->start || cpy == map->end)
		{
			label = (cpy == map->start) ? LABEL_START : LABEL_END;
			ft_dprintf(fd, "\t\"%s\" [%s, %s];\n", cpy->id, label, GV_STARTEND);
		}
		else if (cpy->way)
			ft_dprintf(fd, "\t\"%s\" [%s];\n", cpy->id, GV_NODE_WAY);
		else
			ft_dprintf(fd, "\t\"%s\" %s\n", cpy->id, GV_NODE);
		fdprint_links(map, cpy, fd);
		cpy = cpy->next;
	}
}
static void	write_dotfile(t_map *map, int fd)
{
	ft_dprintf(fd, "graph G {\n");
	ft_dprintf(fd, "\t%s;\n", GV_CONCENTRATE);
	ft_dprintf(fd, "\t%s;\n", GV_BGCOLOR);
	if ((map->flags & FLAG_GRAPH_LR) != 0)
		ft_dprintf(fd, "\t%s;\n", GV_RANKDIR_LR);
	ft_dprintf(fd, "\t%s;\n", GV_EDGE);
	ft_dprintf(fd, "\t%s;\n\n", GV_NODE);
	fdprint_rooms_links(map, fd);
	ft_putstr_fd("}\n\0", fd);
}
void	ft_create_graphfile(t_map *map)
{
	int		fd;

	if (ft_file_exists(DOTFILE))
		ft_remove(DOTFILE);
	if ((fd = ft_open_fd(DOTFILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		ft_error(&map, "ft_create_graphfile", 0);
	write_dotfile(map, fd);
	if ((ft_close_fd(fd)) == -1)
		ft_error(&map, "ft_create_graphfile", 0);
	if (!fork())
	{
		if ((execlp ("sh", "sh", GRAPH_SH, DOTFILE, OUTPUTFILE, NULL)) == -1)
		{
			ft_dprintf(2, "Graphviz execution failed\n");
			ft_dprintf(2, "Try:\tdot -Tpng %s -o %s\n", DOTFILE, OUTPUTFILE);
		}
	}
	else
		perror("fork");
}