/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 02:05:45 by asoria            #+#    #+#             */
/*   Updated: 2025/11/26 23:11:27 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo_subvars(t_philo philo, int i)
{
	(void)philo;
	philo.id = i + 1;
	philo.times_died = 0;
	philo.times_eaten = 0;
	philo.times_slept = 0;
	// gettimeofday(program->philos[i].born_time, 0);
	// gettimeofday(program->philos[i].last_meal, 0);
}

void	init_philos(t_program *program)
{
	int	i;
	ssize_t	r;

	i = 0;
	while(i <= program->number_of_philosophers)
	{
		program->philos = malloc(sizeof(t_philo) * program->number_of_philosophers);
		if (!program->philos)
		{
			r = write(2, "Error: malloc", 14);
			(void)r;
			return ;
		}
		i++;
	}
	i = 0;
	while(i < program->number_of_philosophers)
	{
		init_philo_subvars(program->philos[i], i);
		i++;
	}
	debug_print(program);
}
