/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:47:24 by asoria            #+#    #+#             */
/*   Updated: 2025/11/28 06:21:56 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	think(t_philo *philo)
{
	printf("%d is thinking", philo->id);
}

void	sleep(t_philo *philo)
{
	printf("%d is thinking", philo->id);
	ft_usleep(philo->time_to_sleep)
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	printf("%d has taken a fork", philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("%d has taken a fork", philo->id);
}
