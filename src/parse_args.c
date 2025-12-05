/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/05 21:05:06 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (write(2, "Wrong number of arguments\n", 27));
	else if (ft_atoi(argv[1]) > MAX_PHILO || ft_atoi(argv[1]) <= 0
		|| check_args(argv[1]) == 1)
		return (write(2, "Wrong number_of_philosophers\n", 30));
	else if (ft_atoi(argv[2]) <= 0 || check_args(argv[2]) == 1)
		return (write(2, "Wrong time_to_die\n", 19));
	else if (ft_atoi(argv[3]) <= 0 || check_args(argv[3]) == 1)
		return (write(2, "Wrong time_to_eat\n", 19));
	else if (ft_atoi(argv[4]) <= 0 || check_args(argv[4]) == 1)
		return (write(2, "Wrong time_to_sleep\n", 21));
	else if (argc == 6 && (ft_atoi(argv[5]) > MAX_PHILO
			|| ft_atoi(argv[5]) <= 0 || check_args(argv[5]) == 1))
		return (write(2, "Wrong NoT_each_philosopher_must_eat\n", 30));
	return (0);
}
