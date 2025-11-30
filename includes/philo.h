/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:08 by asoria            #+#    #+#             */
/*   Updated: 2025/11/30 09:50:48 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO 200

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int		id;
	int		*dead;
	size_t		times_died;
	size_t		times_eaten;
	size_t		times_slept;
	size_t		last_meal;
	size_t		born_time;
	pthread_t	thread;
	pthread_mutex_t	fork;
	pthread_mutex_t *r_fork;
}			t_philo;

typedef struct s_program
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_philo		*philos;
	t_time		program_start;
}			t_program;

/* parse_args.c */
int	parse_args(int argc, char **argv);

/* init.c */
void	init(char **argv, t_program *program);

/* utils.c */
int	ft_atoi(const char *str);

/* routine.c */
void	philo_think(t_program *program);
void	philo_eat(t_program *program);
void	philo_sleep(t_program *program);
void	*philo_routine(void *arg);

/* time.c */
t_time	ft_get_time(void);
t_time	time_since_ps(t_program *program);

/* debug.c */
void	debug_print();

#endif
