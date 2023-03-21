/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:06:41 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/21 20:31:36 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define FORK "\033[1;33mhas taken a fork\033[0m\033[0m\033[0m\033[0m\033[0m"
# define EAT "\033[1;32mis eating\033[0m\033[0m\033[0m\033[0m"
# define SLEEP "\033[1;36mis sleeping\033[0m\033[0m\033[0m"
# define THINK "\033[1;34mis thinking\033[0m\033[0m"
# define DIED "\e[0;31mDIED\e[m"
# define LEFT 0
# define RIGHT 1

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	char			**argv;
	int				argc;
	int				nb_philo;
	int				t2d;
	int				t2e;
	int				t2s;
	int				max_meal;
	int				g_status;
	pthread_mutex_t	print;
	pthread_t		*threads;
	t_philo			*philos;
};

struct s_philo
{
	int				id;
	long long		time_lmeal;
	int				meal_eaten;
	int				dead;
	pthread_mutex_t	fork;
	t_data			*data;
};

/*-------parse-----------------------------*/

int	parse(t_data *d, t_philo **p);

/*-------utils-----------------------------*/

int	ft_atoi(const char *str);

#endif