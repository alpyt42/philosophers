/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:06:41 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/23 23:55:56 by ale-cont         ###   ########.fr       */
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

typedef struct s_rules
{
	int				nb_philo;
	int				ready;
	int				t2d;
	int				t2e;
	int				t2s;
	int				max_meal;
	int				check_meal;
	int				game_over;
	int				all_ate;
	long int		start;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				meal_eaten;
	long int		thread_start;
	long int		time_last_meal;
	pthread_t		life;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	t_rules		*rules;
}	t_philo;

int			error(char *str, t_rules *r, t_philo *p);
int			ft_atoi(const char *str);
long int	time_get(void);
int			init_philo(t_rules *r, t_philo *p);
void		*routine(void *per);
void		p_rout(t_philo *p, char *str);
void		ft_sleep(long int time);
int			philo(t_rules *r);
int			check_death(t_philo *p);
int			check_meal(t_philo *p);
int			dead(t_philo *p);

#endif