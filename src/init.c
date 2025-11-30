/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 02:05:45 by asoria            #+#    #+#             */
/*   Updated: 2025/11/30 09:49:12 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philosophers)
	{		
		pthread_mutex_init(&program->philos[i].fork, NULL);
			program->philos[i].r_fork = &program->philos[(i + 1) % program->number_of_philosophers].fork;
		i++;
	}
}

static void	init_philos(t_program *program)
{
	int	i;

	program->philos = malloc(sizeof(t_philo) * program->number_of_philosophers);
	if (!program->philos)
		return ;
	i = 0;
	while(i < program->number_of_philosophers)
	{
		program->philos[i].id = i + 1;
		program->philos[i].dead = 0;
		program->philos[i].times_died = 0;
		program->philos[i].times_eaten = 0;
		program->philos[i].times_slept = 0;
		i++;
	}
}

static void	init_program(char **argv, t_program *program)
{
	program->program_start = ft_get_time();
	program->number_of_philosophers = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		program->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		program->number_of_times_each_philosopher_must_eat = -1;

}

void	init(char **argv, t_program *program)
{
	init_program(argv, program);
	init_philos(program);
	init_forks(program);
}
