/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:01:22 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 22:04:37 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utility.h"
#include <stdlib.h>
#include "map.h"

int		valid_legend(char *legend, int length)
{
	int		i;

	if (length < 4 || length > 12)
		return (0);
	i = length - 4;
	while (i >= 0)
	{
		if (legend[i] < '0' || legend[i] > '9')
			return (0);
		i--;
	}
	if (legend[length - 1] == legend[length - 2]
			|| legend[length - 1] == legend[length - 3]
			|| legend[length - 2] == legend[length - 3])
		return (0);
	return (1);
}

int		valid_line(char *line, t_map_info *map_info)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != map_info->obstacol && line[i] != map_info->vid)
			return (0);
		i++;
	}
	if (i != map_info->fl_length)
		return (0);
	return (1);
}
