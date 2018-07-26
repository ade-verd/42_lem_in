/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:50:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/26 18:50:32 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_check_args(t_map *map, char *str)
{
	if (str[0] == '-' && (ft_strchr(str, 'h') || ft_strchr(str, 'H')))
		map->flags = map->flags | FLAG_HELP;
	if (str[0] == '-' && (ft_strchr(str, 'd') || ft_strchr(str, 'D')))
		map->flags = map->flags | FLAG_DEBUG_FLAGS;
	if (str[0] == '-' && (ft_strchr(str, 'r') || ft_strchr(str, 'R')))
		map->flags = map->flags | FLAG_ROOMS;
	if (str[0] == '-' && ft_strchr(str, 'w'))
		map->flags = map->flags | FLAG_WAYS_SEL;
	if (str[0] == '-' && ft_strchr(str, 'W'))
		map->flags = map->flags | FLAG_WAYS_ALL;
	if (str[0] == '-' && (ft_strchr(str, 's') || ft_strchr(str, 'S')))
		map->flags = map->flags | FLAG_STATUS;
	if (str[0] == '-' && (ft_strchr(str, 'c') || ft_strchr(str, 'C')))
		map->flags = map->flags | FLAG_CONTEXT_NO;
	if (str[0] == '-' && (ft_strchr(str, 'm') || ft_strchr(str, 'M')))
	{
		map->flags = map->flags | FLAG_MUTE;
		map->flags = map->flags | FLAG_CONTEXT_NO;
		map->flags = map->flags | FLAG_STATUS;
	}
	if (str[0] == '-' && ft_strchr(str, 'g'))
		map->flags = map->flags | FLAG_GRAPH_TB;
	if (str[0] == '-' && ft_strchr(str, 'G'))
		map->flags = map->flags | FLAG_GRAPH_LR;
}

void		ft_read_args(t_map **map, int ac, char **av)
{
	char	**tab;
	int		i;

	while (ac > 1)
	{
		ac--;
		i = ft_countwords(av[ac], ' ');
		tab = ft_strsplit(av[ac], ' ');
		while (--i >= 0)
			ft_check_args(*map, tab[i]);
		ft_freetab_strsplit(tab);
	}
}

void		starts_with_hashtag(t_map **map, char *line, int *loop)
{
	if (ft_strcmp(line, "##start") == 0)
		(*map)->command = CMD_START;
	else if (ft_strcmp(line, "##end") == 0)
		(*map)->command = CMD_END;
	if ((*map)->command && (*map)->ants <= 0)
		*loop = 0;
}

void		ft_read_fd(t_map **map)
{
	int		ret;
	int		loop;
	char	*line;

	loop = 1;
	while (loop && (ret = get_next_line((*map)->fd, &line)) > 0)
	{
		if (line[0] == '#')
			starts_with_hashtag(map, line, &loop);
		else if (ft_countwords(line, ' ') == 3 && ft_isroom(line, &loop))
			ft_add_room(map, ft_strsplit(line, ' '));
		else if (ft_countwords(line, '-') == 2 && ft_islink(map, line, &loop))
			ft_add_link(map, ft_strsplit(line, '-'));
		else if (ft_countwords(line, ' ') == 1 && ft_isant(line, &loop))
			(*map)->ants += ft_atointmax(line);
		else
			loop = 0;
		if (loop)
			ft_add_line(*map, ft_strdup(line));
		ft_strdel(&line);
	}
	line ? ft_strdel(&line) : none();
	ret < 0 ? ft_error(map, "ft_reader: GNL Bad return", 0) : none();
}
