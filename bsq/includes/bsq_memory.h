/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_memory.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:13:00 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 20:13:21 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_MEMORY_H
# define BSQ_MEMORY_H

# include "bsq_info.h"
# include "map.h"

void	ft_init(t_bsq_info *bsq_info, t_map_info *map_info);
void	ft_uninit(t_bsq_info *bsq_info);

#endif
