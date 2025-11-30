/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:47:24 by asoria            #+#    #+#             */
/*   Updated: 2025/11/30 09:51:28 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	printf("%d is thinking", philo->id);
}

void	philo_sleep(t_program *program)
{
	printf("%d is thinking", program->philos->id);
	usleep(program->time_to_sleep);
}

void	philo_eat(t_program *program)
{
	pthread_mutex_lock(&program->philos->fork);
	printf("%llu %d has taken a fork\n", time_since_ps(program), philo->id);
	pthread_mutex_lock(program->philos->r_fork);
	printf("%llu %d has taken a fork\n", time_since_ps(program), philo->id);
}

void	*philo_routine(void *arg)
{

	return ((void *)0);
}
