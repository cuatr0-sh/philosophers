/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:09:11 by asoria            #+#    #+#             */
/*   Updated: 2025/12/16 19:34:55 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		return (1);
	if (parse_args(argc, argv) != 0)
		return (free(program), 1);
	init(argv, program);
	if (program->number_of_philosophers == 1)
	{
		safe_print(program, program->philos[0].id, "has taken a fork");
		usleep(program->time_to_die * 1000);
		safe_print(program, program->philos[0].id, "died");
		black_hole(program);
		return (0);
	}
	create_threads(program);
	join_threads(program);
	black_hole(program);
	return (0);
}
