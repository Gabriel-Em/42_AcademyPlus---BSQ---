/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:53:33 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 21:18:38 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_utility.h"

void	display_line(int *result, t_map_info *map_info, int i, char *line)
{
	int j;

	j = 0;
	while (line[j] != '\0')
	{
		if (i >= result[1] - result[0] + 1 && i <= result[1] && j >= result[2]
				- result[0] + 1 && j <= result[2])
			ft_putchar(map_info->plin);
		else
			ft_putchar(line[j]);
		j++;
	}
}

void	display_result(char *file_name, int *result, t_map_info *map_info)
{
	int		fd;
	char	*buf;
	int		ret;
	int		i;

	i = 0;
	buf = (char*)malloc(sizeof(char) * (ft_max(map_info->fl_length,
					map_info->legend_length) + 2));
	fd = open(file_name, O_RDONLY);
	read(fd, buf, map_info->legend_length + 1);
	while ((ret = read(fd, buf, map_info->fl_length + 1)))
	{
		buf[ret] = '\0';
		display_line(result, map_info, i, buf);
		i++;
	}
	close(fd);
	free(buf);
}
