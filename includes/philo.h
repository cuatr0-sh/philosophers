/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:08 by asoria            #+#    #+#             */
/*   Updated: 2025/11/25 01:53:48 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	int	id;
	size_t	times_died;
	size_t	times_eaten;
	size_t	times_slept;
	size_t	last_meal;
	size_t	born_time;
}	t_philo;

typedef struct s_program
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*forks;
	t_philo		*philos;
}			t_program;

/* parse_args.c */
int	parse_args(int argc, char **argv, t_program *program);

/* utils.c */
int	ft_atoi(const char *str);

#endif
