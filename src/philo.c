/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:09:11 by asoria            #+#    #+#             */
/*   Updated: 2025/11/28 07:49:10 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program *program;

	program = malloc(sizeof(t_program));
	if (parse_args(argc, argv) != 0)
		return (1);
	init(argv, program);
	debug_print(program);
	return (0);
}
