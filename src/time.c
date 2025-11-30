/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 08:55:50 by asoria            #+#    #+#             */
/*   Updated: 2025/11/30 09:42:41 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	ft_get_time(void)
{
	struct timeval	tp;
	t_time		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000 + tp.tv_usec / 1000);
	return (time);
}

t_time	time_since_ps(t_program *program)
{
	t_time	time_diff;

	time_diff = program->program_start - ft_get_time();
	return (time_diff);
}
