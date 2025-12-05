/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:08 by asoria            #+#    #+#             */
/*   Updated: 2025/12/05 00:57:06 by asoria           ###   ########.fr       */
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

typedef struct s_program t_program;

typedef struct s_philo
{
	int		id;
	int		*dead;
	size_t		times_died;
	size_t		times_eaten;
	size_t		times_slept;
	t_time		last_meal;
	t_time		born_time;
	pthread_t	thread;
	pthread_mutex_t	fork;
	pthread_mutex_t *r_fork;
	t_program	*program;
}			t_philo;

typedef struct s_program
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	int		dead;
	t_philo		*philos;
	t_time		program_start;
	pthread_t	monitor_thread;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
}			t_program;

/* parse_args.c */
int	parse_args(int argc, char **argv);

/* init.c */
void	init(char **argv, t_program *program);
void	init_program(char **argv, t_program *program);

/* threads.c */
void	create_threads(t_program *program);
void	join_threads(t_program *program);

/* utils.c */
int	is_dead(t_program *program);
void	set_dead(t_program *program);
void	safe_print(t_program *program, int philo_id, char *message);
void	black_hole(t_program *program);
int	ft_atoi(const char *str);

/* routine.c */
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	*philo_routine(void *arg);

/* time.c */
t_time	ft_get_time(void);
t_time	time_since_ps(t_program *program);

/* monitor.c */
void	*monitor_routine(void *arg);

/* debug.c */
void	debug_print();

#endif
