/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:57:07 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 22:00:15 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "validator.h"
#include <stdlib.h>
#include "bsq.h"
#include "map.h"
#include "ft_utility.h"

int		ft_get_lengths(char *file_name, int *legenda_length, int *fl_length)
{
	int		fd;
	int		lines;
	char	c;

	*legenda_length = 0;
	*fl_length = 0;
	lines = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) && lines < 2)
	{
		if (c == '\n')
			lines++;
		else
		{
			if (lines == 0)
				*legenda_length += 1;
			else
				*fl_length += 1;
		}
	}
	close(fd);
	if (lines == 0)
		return (0);
	return (1);
}

char	*get_legend(char *file_name, int length)
{
	int		fd;
	char	*legend;

	fd = open(file_name, O_RDONLY);
	legend = (char*)malloc(sizeof(char) * (length + 1));
	read(fd, legend, length);
	legend[length] = '\0';
	close(fd);
	return (legend);
}

int		start_bsq(t_map_info *map_info, int **result, char *file_name,
		int legend_length)
{
	int		res;

	*result = (int*)malloc(sizeof(int) * 3);
	(*result)[0] = 0;
	(*result)[1] = 0;
	(*result)[2] = 0;
	res = solve_bsq(file_name, legend_length, map_info, result);
	return (res);
}

void	update_legend(int legend_length, char *legend, t_map_info *map_info)
{
	char	*no;

	map_info->plin = legend[legend_length - 1];
	map_info->obstacol = legend[legend_length - 2];
	map_info->vid = legend[legend_length - 3];
	no = (char*)malloc(sizeof(char) * (legend_length - 2));
	no = ft_strncpy(no, legend, legend_length - 3);
	no[legend_length - 3] = '\0';
	map_info->nr_linii = ft_atoi(no);
	free(no);
}

int		compute_file(char *file_name, int **result, t_map_info *map_info)
{
	int		legend_length;
	int		fl_length;
	char	*legend;

	if (!ft_get_lengths(file_name, &legend_length, &fl_length))
		return (-1);
	map_info->fl_length = fl_length;
	map_info->legend_length = legend_length;
	legend = get_legend(file_name, legend_length);
	if (!valid_legend(legend, legend_length))
		return (-1);
	update_legend(legend_length, legend, map_info);
	if (!start_bsq(map_info, result, file_name, legend_length))
		return (-1);
	return (0);
}
