/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:05:13 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 22:03:14 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_INFO_H
# define BSQ_INFO_H

typedef	struct	s_bsq_info
{
	char	*line;
	int		*prev_line;
	int		*current_line;
	int		current_i;
	int		current_j;
}				t_bsq_info;

#endif
