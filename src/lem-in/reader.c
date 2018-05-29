/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:07:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/29 11:56:36 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_reader(t_map **map)
{
	int		fd;
	int		ret;
	int		loop;
	char	*line;

	fd = 0;
	loop = 1;
	while (loop && (ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
				command_start(map, fd, &ret, &loop);
			else if (ft_strcmp(line, "##end") == 0)
				command_end(map, fd, &ret, &loop);
			//else if (...)
				//comment
		}
		else if (ft_countwords(line, ' ') == 3 && ft_isroom(line, &loop))
			ft_add_room(map, ft_strsplit(line, ' '));
		else if (ft_countwords(line, '-') == 2 && ft_islink(map, line, &loop))
			ft_add_link(map, ft_strsplit(line, '-'));
		else
			loop = 0;
		ft_strdel(&line);
	}
	line ? ft_strdel(&line) : none();
	ret < 0 ? ft_error(map, "ft_reader: GNL Bad return", 0) : none();
}
