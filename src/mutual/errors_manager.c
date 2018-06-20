/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:35:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/20 13:40:04 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** void	ft_error(t_heaps **ab, char *precision)
** Displays "Error" (and eventually precision), Frees everything, and exit
*/

void	ft_error(t_map **map, char *precision, int errnum)
{
	ft_putstr_fd("ERROR\n", 2);
	if (precision)
		ft_dprintf(2, "%s\n", precision);
	if (errnum > 0)
		ft_dprintf(2, "%s\n", strerror(errnum));
	if (*map)
		ft_map_del(map);
	exit(EXIT_FAILURE);
}

/*
** void	ft_error_sdl(t_heaps **ab, char *precision, char *precision2)
** Same function than ft_error with a second precision for error's details
*/

void	ft_error_sdl(t_map **map, char *precision, char *precision2)
{
	ft_putstr_fd("ERROR\n", 2);
	if (precision)
		ft_dprintf(2, "%s\n", precision);
	if (precision2)
		ft_dprintf(2, "%s\n", precision2);
	if (*map)
		ft_map_del(map);
	exit(EXIT_FAILURE);
}

/*
** int	none(void)
** Does nothing
*/

int		none(void)
{
	return (0);
}
