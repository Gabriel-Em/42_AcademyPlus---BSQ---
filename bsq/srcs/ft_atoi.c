/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:56:25 by gpop              #+#    #+#             */
/*   Updated: 2017/08/02 19:56:49 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ignored_space(char s)
{
	if (s == ' ' || s == '\n' || s == '\t')
		return (1);
	if (s == '\r' || s == '\v' || s == '\f')
		return (1);
	return (0);
}

int		ft_generate_number(char *str)
{
	int nr;
	int i;

	nr = 0;
	i = 0;
	while (i <= 19 && str[i] >= '0' && str[i] <= '9')
	{
		nr = nr * 10 + str[i] - '0';
		i++;
	}
	if (i == 20)
		return (-1);
	else
		return (nr);
}

int		ft_atoi(char *str)
{
	int i;
	int nr;
	int semn;

	i = 0;
	nr = 0;
	semn = 1;
	while (ignored_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		semn = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nr = ft_generate_number(str + i);
	if (nr == -1)
		return (nr);
	return (nr * semn);
}
