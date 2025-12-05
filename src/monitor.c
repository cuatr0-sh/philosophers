/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:07:13 by asoria            #+#    #+#             */
/*   Updated: 2025/12/05 01:01:59 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	everyone_ate(t_program *program)
{
	int	i;
	size_t	meals_eaten;

	i = 0;

	if (program->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (i < program->number_of_philosophers)
	{
		pthread_mutex_lock(&program->meal_mutex);
		meals_eaten = program->philos[i].times_eaten;
		pthread_mutex_unlock(&program->meal_mutex);
		if (meals_eaten <
				(size_t)program->number_of_times_each_philosopher_must_eat)
			return (0);
		i++;
	}
	set_dead(program);
	return (1);
}

static int	someone_died(t_program *program)
{
	int	i;
	long long	diff;

	i = 0;
	while (i < program->number_of_philosophers)
	{
		diff = ft_get_time() - program->philos[i].last_meal;
		if (diff > program->time_to_die)
		{
			safe_print(program, program->philos[i].id, "died");
			set_dead(program);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_program	*program;

	program = (t_program *)arg;
	usleep(1000);
	while (!is_dead(program))
	{
		if (someone_died(program) || everyone_ate(program))
			break;
		usleep(1000);
	}
	return NULL;
}
