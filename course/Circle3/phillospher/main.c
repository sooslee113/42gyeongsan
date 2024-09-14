/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:10 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/11 14:55:59 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"
int mails = 0;
pthread_mutex_t mutex;

void* routine() 
{
	pthread_mutex_lock(&mutex);
    for (int i = 0; i < 5; i++) 
	{    
        mails++;
    }
	pthread_mutex_unlock(&mutex);
	return NULL;
}


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
	//int i;
	t_program *program;
	t_philo *philo;
	
	program = NULL;
	philo = NULL;
	//i = 0;
	if (argc != 5 && argc != 6)
		show_error("argc is wrong");

	check_argv(argc, argv);
	init_argv(&program, argv);
	if (!program)
		show_error("Failed to initialize program\n");
	init_phillo (&philo, program);
	printf("number_of_philo : %d\n", program -> number_of_philo);
	pthread_mutex_init(&mutex, NULL);
	// while(i < program -> number_of_philo)
	// {
	// 	pthread_create(&(program->philo[i].thread), NULL, &routine, (void *)program);
	// 	printf("id : %d has started\n", program->philo[i].id);
	// 	printf("i의 값 : %d\n", i);
	// 	i ++;
	// }
	printf("phthread_create 빠져 나옴\n");
	//i = 0;
	// while(i < program -> number_of_philo)
	// {
	// 	pthread_join(program->philo[i].thread, NULL);
	// 	printf("id : %d has finished\n", program->philo[i].id);
	// 	printf("i의 값 : %d\n", i);
	// 	i ++;
	// }
	pthread_mutex_destroy(&mutex);
	//free(program->forks);
	free(philo);
	free(program);
	printf("mails 의 값 : %d",mails);
	return (0);
}
