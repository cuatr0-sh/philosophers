/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:59:25 by asoria            #+#    #+#             */
/*   Updated: 2025/12/06 13:53:26 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_dead(t_program *program)
{
	int	dead;

	pthread_mutex_lock(&program->dead_mutex);
	dead = program->dead;
	pthread_mutex_unlock(&program->dead_mutex);
	return (dead);
}

void	set_dead(t_program *program)
{
	pthread_mutex_lock(&program->dead_mutex);
	program->dead = 1;
	pthread_mutex_unlock(&program->dead_mutex);
}

void	safe_print(t_program *program, int philo_id, char *message)
{
	pthread_mutex_lock(&program->write_mutex);
	if (!program->dead)
		printf("%llu %d %s\n", time_since_ps(program), philo_id, message);
	pthread_mutex_unlock(&program->write_mutex);
}

void	black_hole(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philosophers)
	{
		pthread_mutex_destroy(&program->philos[i].fork);
		i++;
	}
	pthread_mutex_destroy(&program->dead_mutex);
	pthread_mutex_destroy(&program->write_mutex);
	pthread_mutex_destroy(&program->meal_mutex);
	free(program->philos);
	free(program);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
