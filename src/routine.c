/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:47:24 by asoria            #+#    #+#             */
/*   Updated: 2025/12/01 23:47:56 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	t_program	*program;
	
	program = philo->program;
	printf("%d is thinking", philo->id);
}

void	philo_sleep(t_philo *philo)
{
	t_program	*program;
	
	program = philo->program;
	printf("%d is thinking", philo->id);
	usleep(program->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	t_program	*program;
	
	program = philo->program;
	pthread_mutex_lock(&program->philos->fork);
	printf("%llu %d has taken a fork\n", time_since_ps(program),
		program->philos->id);
	pthread_mutex_lock(program->philos->r_fork);
	printf("%llu %d has taken a fork\n", time_since_ps(program),
		program->philos->id);
	printf("%llu %d is eating\n", time_since_ps(program),
		program->philos->id);
}

void	philo_actions(t_philo *philo)
{
	philo
}

void	*philo_routine(void *arg)
{
	int		i;
	t_philo 	*philo;
	t_program	*program;

	philo = (t_philo *)arg;
	program = philo->program;
	i = 0;
	while (i < program->number_of_philosophers)
	{
		pthread_create(&program->philos[i].thread, NULL,
			philo_actions, program);
		i++;
	}
	return NULL;
}
