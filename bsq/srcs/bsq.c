/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:48:40 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 22:33:24 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "validator.h"
#include "map.h"
#include "bsq_info.h"
#include "ft_utility.h"
#include "bsq_memory.h"

int		read_next_line(int fd, t_bsq_info *bsq_info, t_map_info *map_info)
{
	int		ret;
	char	c;

	c = ' ';
	ret = read(fd, bsq_info->line, map_info->fl_length);
	bsq_info->line[ret] = '\0';
	ret = read(fd, &c, 1);
	if (c != '\n')
		return (0);
	return (valid_line(bsq_info->line, map_info));
}

void	compute_bsq_line(t_map_info *map_info, t_bsq_info *bsq_info,
		int **result)
{
	int minim;

	bsq_info->current_j = 0;
	while (bsq_info->current_j < map_info->fl_length)
	{
		if (bsq_info->line[bsq_info->current_j] != map_info->obstacol)
		{
			if (bsq_info->current_j == 0)
				minim = 0;
			else
				minim = ft_min(bsq_info->prev_line[bsq_info->current_j],
						bsq_info->prev_line[bsq_info->current_j - 1],
						bsq_info->current_line[bsq_info->current_j - 1]);
			bsq_info->current_line[bsq_info->current_j] = minim + 1;
			if (minim + 1 > (*result)[0])
			{
				(*result)[0] = minim + 1;
				(*result)[1] = bsq_info->current_i;
				(*result)[2] = bsq_info->current_j;
			}
		}
		else
			bsq_info->current_line[bsq_info->current_j] = 0;
		bsq_info->current_j++;
	}
}

void	init_prev(t_bsq_info *bsq_info, t_map_info *map_info)
{
	bsq_info->current_j = 0;
	while (bsq_info->current_j < map_info->fl_length)
	{
		bsq_info->prev_line[bsq_info->current_j] =
			bsq_info->current_line[bsq_info->current_j];
		bsq_info->current_j++;
	}
}

int		return_message(int fd, int error, t_bsq_info *bsq_info)
{
	close(fd);
	ft_uninit(bsq_info);
	return (error);
}

int		solve_bsq(char *file_name, int legend_length, t_map_info *map_info,
		int **result)
{
	int			fd;
	t_bsq_info	bsq_info;

	bsq_info.current_i = 0;
	ft_init(&bsq_info, map_info);
	fd = open(file_name, O_RDONLY);
	read(fd, bsq_info.line, legend_length + 1);
	while (map_info->nr_linii > 0)
	{
		if (!read_next_line(fd, &bsq_info, map_info))
			return (return_message(fd, 0, &bsq_info));
		compute_bsq_line(map_info, &bsq_info, result);
		init_prev(&bsq_info, map_info);
		map_info->nr_linii--;
		bsq_info.current_i++;
	}
	if (read(fd, bsq_info.line, 1))
		return (return_message(fd, 0, &bsq_info));
	return (return_message(fd, 1, &bsq_info));
}
