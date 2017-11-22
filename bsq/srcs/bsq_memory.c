/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:52:52 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 19:53:20 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_info.h"
#include "map.h"
#include <stdlib.h>
#include "ft_utility.h"

void	ft_uninit(t_bsq_info *bsq_info)
{
	free(bsq_info->line);
	free(bsq_info->prev_line);
	free(bsq_info->current_line);
}

void	ft_init(t_bsq_info *bsq_info, t_map_info *map_info)
{
	int i;

	bsq_info->prev_line = (int*)malloc(sizeof(int) * (map_info->fl_length + 1));
	bsq_info->current_line = (int*)malloc(sizeof(int) * (map_info->fl_length +
				1));
	bsq_info->line = (char*)malloc(sizeof(char) * (ft_max(map_info->fl_length,
					map_info->legend_length) + 2));
	i = 0;
	while (i < map_info->fl_length)
	{
		(bsq_info->current_line)[i] = 0;
		(bsq_info->prev_line)[i++] = 0;
	}
	bsq_info->current_i = 0;
}
