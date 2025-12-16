/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:47:24 by asoria            #+#    #+#             */
/*   Updated: 2025/12/05 23:28:42 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	safe_print(philo->program, philo->id, "is thinking");
}

void	philo_sleep(t_philo *philo)
{
	safe_print(philo->program, philo->id, "is sleeping");
	usleep(philo->program->time_to_sleep * 1000);
	philo->times_slept++;
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	safe_print(philo->program, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	safe_print(philo->program, philo->id, "has taken a fork");
	safe_print(philo->program, philo->id, "is eating");
	pthread_mutex_lock(&philo->program->meal_mutex);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->program->meal_mutex);
	usleep(philo->program->time_to_eat * 1000);
	pthread_mutex_lock(&philo->program->meal_mutex);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->program->meal_mutex);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->fork);
}

static int	has_eaten_enough(t_philo *philo)
{
	int			done;
	t_program	*program;

	program = philo->program;
	if (program->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	pthread_mutex_lock(&program->meal_mutex);
	done = philo->times_eaten
		>= (size_t)program->number_of_times_each_philosopher_must_eat;
	pthread_mutex_unlock(&program->meal_mutex);
	return (done);
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_program	*program;

	philo = (t_philo *)arg;
	program = philo->program;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!is_dead(program))
	{
		if (is_dead(program))
			break ;
		philo_think(philo);
		if (is_dead(program))
			break ;
		philo_eat(philo);
		if (has_eaten_enough(philo) || is_dead(program))
			break ;
		philo_sleep(philo);
	}
	return (NULL);
}
