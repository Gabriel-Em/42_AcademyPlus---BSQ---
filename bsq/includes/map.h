/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:07:43 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 20:08:05 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map_info
{
	int		fl_length;
	int		legend_length;
	int		nr_linii;
	char	vid;
	char	obstacol;
	char	plin;
}				t_map_info;

#endif
