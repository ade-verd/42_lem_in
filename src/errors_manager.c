/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:35:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 17:25:16 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** void	ft_error(t_map **map, char *precision, int errnum)
** Displays "Error" (and eventually precision), Frees everything, and exit
*/

void	ft_error(t_map **map, char *precision, int errnum)
{
	int	nothing;

	nothing = ft_strcmp(precision, "NO");
	if (nothing != 0)
		ft_putstr_fd("ERROR\n", 2);
	if (precision && nothing != 0)
		ft_dprintf(2, "%s\n", precision);
	if (errnum > 0)
		ft_dprintf(2, "%s\n", strerror(errnum));
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
