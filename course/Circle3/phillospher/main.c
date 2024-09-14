/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:10 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/14 18:18:28 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

int is_argv_num(char *argv)
{
	while(*argv != '\0')
	{
		if (*argv < '0' || *argv > '9')
			return (1);
		argv ++;
	}
	return (0);
}

void	check_argv(int argc, char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0)
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

int main(int argc, char **argv)
{
	t_program *program;
	t_philo *philo;

	program = NULL;
	philo = NULL;
	if (argc != 5 && argc != 6)
		show_error("argc is wrong");
	check_argv(argc, argv);
	init_argv(&program, argv);
	init_phillo (&philo, program);
	printf("hello world\n");
	free(philo);
	free(program);
	return (0);
}
