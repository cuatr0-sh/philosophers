/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:46:11 by asoria            #+#    #+#             */
/*   Updated: 2025/11/30 08:39:56 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	debug_print(t_program *program)
{
	int	i;

	i = 0;
	printf("number_of_philosophers: %d\n", program->number_of_philosophers);
	printf("time_to_die: %d\n", program->time_to_die);
	printf("time_to_eat: %d\n", program->time_to_eat);
	printf("time_to_sleep: %d\n", program->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n", program->number_of_times_each_philosopher_must_eat);
	printf("\n");

	while (i < program->number_of_philosophers)
	{
		printf("Philo[%d]:\n", i + 1);
		printf("\ttimes_died: %ld\n", program->philos[i].times_died);
		printf("\ttimes_eaten: %ld\n", program->philos[i].times_eaten);
		printf("\ttimes_slept: %ld\n", program->philos[i].times_slept);
		i++;
	}
}
