/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:39:22 by asoria            #+#    #+#             */
/*   Updated: 2025/12/05 00:38:41 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	pthread_create(&program->monitor_thread, NULL, monitor_routine, program);
	while (i < program->number_of_philosophers)
	{
		pthread_create(&program->philos[i].thread, NULL,
				philo_routine, &program->philos[i]);
		i++;
	}
}

void	join_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philosophers)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
	pthread_join (program->monitor_thread, NULL);
}
