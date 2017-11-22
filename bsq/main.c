/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:46:07 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 22:45:30 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_file.h"
#include "map.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	read_from_std_input(void)
{
	int		ret;
	char	*buf;
	int		fd;

	fd = open("./std_input.txt", O_RDWR | O_CREAT, 0644);
	buf = (char*)malloc(51 * sizeof(char));
	while ((ret = read(0, buf, 50)))
		write(fd, buf, ret);
	close(fd);
	free(buf);
}

int		exista_fisier(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	process_file(char *file_name, int **result, t_map_info *map_info)
{
	if (exista_fisier(file_name))
	{
		if (compute_file(file_name, result, map_info) == -1)
			write(2, "map error\n", 10);
		else if ((*result)[0] == 0)
			write(2, "map error\n", 10);
		else
			display_result(file_name, *result, map_info);
		if (*result != 0)
		{
			free(*result);
			*result = 0;
		}
	}
	else
		write(2, "map error\n", 10);
}

int		main(int argc, char **argv)
{
	int			*result;
	t_map_info	map_info;
	int			i;

	result = 0;
	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			process_file(argv[i], &result, &map_info);
			i++;
		}
	else
	{
		read_from_std_input();
		process_file("./std_input.txt", &result, &map_info);
	}
	return (0);
}
