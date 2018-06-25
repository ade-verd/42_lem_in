/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:07:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/20 20:19:27t by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_check_args(t_map **map, char *str)
{
	if (str[0] == '-' && ft_strchr(str, 'f'))
		(*map)->option_f = 1;
	ft_strstr(str, ".txt") ? (*map)->path = ft_strdup(str) : (*map)->path;
}

void		ft_read_args(t_map **map, int ac, char **av)
{
	char	**tab;
	int 	i;

	while (ac > 1)
	{
		ac--;
		i = ft_countwords(av[ac], ' ');
		tab = ft_strsplit(av[ac], ' ');
		while (--i >= 0)
			ft_check_args(map, tab[i]);
		ft_freetab_strsplit(tab);
	}
}

void		starts_with_hashtag(t_map **map, char *line, int *loop)
{
	if (ft_strcmp(line, "##start") == 0)
		(*map)->command = CMD_START;
	else if (ft_strcmp(line, "##end") == 0)
		(*map)->command = CMD_END;
	//else if (...)
		//comment
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
