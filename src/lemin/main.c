/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/26 18:32:25 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	t_map	*map;

	ft_map_init(&map);
	if (ac > 1)
		ft_read_args(&map, ac, av);
	ft_deal_options(&map);
	ft_read_fd(&map);
	find_issues(map, map->head, 0);
	ft_check_validity(map);
	ft_read_ways(map);
	ft_sort_issues(map);
	ft_select_issues(map);
	ft_read_lines(map);
	ft_read_ways(map);
	solve(map);
	ft_deal_options_quit(&map);
	ft_map_del(&map);
	return (EXIT_SUCCESS);
}
