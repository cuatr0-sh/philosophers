/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:09:11 by asoria            #+#    #+#             */
/*   Updated: 2025/11/30 19:57:32 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	i;
	t_program *program;

	program = malloc(sizeof(t_program));
	if (parse_args(argc, argv) != 0)
		return (1);
	init(argv, program);
	i = 0;
	while (i < program->number_of_philosophers)
	{
		pthread_create(&program->philos[i].thread, NULL,
			philo_routine, &program);
		i++;
	}
	debug_print(program);
	return (0);
}
