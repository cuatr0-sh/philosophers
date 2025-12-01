/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:47:24 by asoria            #+#    #+#             */
/*   Updated: 2025/12/02 00:52:28 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	(void)philo;
	printf("%d is thinking\n", philo->id);
}

void	philo_sleep(t_philo *philo)
{
	t_program	*program;
	
	program = philo->program;
	printf("%d is sleeping\n", philo->id);
	usleep(program->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	t_program	*program;
	
	program = philo->program;
	pthread_mutex_lock(&philo->fork);
	printf("%llu %d has taken a fork\n", time_since_ps(program),
		philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("%llu %d has taken a fork\n", time_since_ps(program),
		philo->id);
	printf("%llu %d is eating\n", time_since_ps(program),
		philo->id);
}

void	*philo_routine(void *arg)
{
	t_philo 	*philo;
	//t_program	*program;

	philo = (t_philo *)arg;
	//program = philo->program;
	philo_think(philo);
	philo_eat(philo);
	philo_sleep(philo);
	return NULL;
}
