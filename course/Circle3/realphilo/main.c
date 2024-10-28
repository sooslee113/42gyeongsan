/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:09:05 by sooslee           #+#    #+#             */
/*   Updated: 2024/10/28 20:12:09 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

int	is_argv_num(char *argv)
{
	while (*argv != '\0')
	{
		if (*argv < '0' || *argv > '9')
			return (1);
		argv ++;
	}
	return (0);
}

void	check_argv(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
		show_error("The number of phillo is wrong\n");
	if (ft_atoi(argv[2]) <= 0 || is_argv_num(argv[2]) == 1)
		show_error("Dying time is wrong\n");
	if (ft_atoi(argv[3]) <= 0 || is_argv_num(argv[3]) == 1)
		show_error("Eatting time is wrong\n");
	if (ft_atoi(argv[4]) <= 0 || is_argv_num(argv[4]) == 1)
		show_error("Sleeping time is wrong\n");
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0 || is_argv_num(argv[5]) == 1)
			show_error("The number of times to eat is wrong\n");
	}
}

/*
./philo '철학자 수', '죽는 시간', '먹는 시간'. '자는 시간', [철학자가 먹어야 하는 끼니]
*/
int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		check_argv(argc, argv);
		data_init(&table, argv);
		dinner_start(&table);
		clean(&table);
	}
	else
	{
		show_error("Input is Wrong");
	}
	return (0);
}
