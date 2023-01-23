/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:45:33 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/24 00:01:15 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_philo *p)
{
	long int	time;

	time = -1;
	time = time_get() - p->rules->start;
	// pthread_mutex_unlock(p->lf);
	// pthread_mutex_unlock(p->rf);
	// pthread_mutex_lock(p->rules->writing);
	if (time >= 0 && time <= 2147483647)
		printf("[%ldms] Philo %d %s\n", time, p->id + 1, DIED);
	// printf("Philo %d DIED", p->id + 1);
	// pthread_mutex_unlock(p->rules->writing);
	p->rules->game_over = 1;
	p->dead = 1;
	return (1);
}

static void	eat(t_philo *p)
{
	pthread_mutex_lock(p->lf);
	pthread_mutex_lock(p->rules->writing);
	p_rout(p, FORK);
	pthread_mutex_unlock(p->rules->writing);
	if (!p->rf)
	{
		ft_sleep(p->rules->t2d * 2);
		return ;
	}
	pthread_mutex_lock(p->rf);
	pthread_mutex_lock(p->rules->writing);
	p_rout(p, FORK);
	pthread_mutex_unlock(p->rules->writing);
	p->time_last_meal = time_get();
	pthread_mutex_lock(p->rules->writing);
	p_rout(p, EAT);
	pthread_mutex_unlock(p->rules->writing);
	ft_sleep(p->rules->t2e);
	p->meal_eaten++;
	pthread_mutex_unlock(p->lf);
	pthread_mutex_unlock(p->rf);
}

static void	sleep_think(t_philo *p)
{
	pthread_mutex_lock(p->rules->writing);
	p_rout(p, SLEEP);
	pthread_mutex_unlock(p->rules->writing);
	ft_sleep(p->rules->t2s);
	pthread_mutex_lock(p->rules->writing);
	p_rout(p, THINK);
	pthread_mutex_unlock(p->rules->writing);
}

void	*routine(void *per)
{
	t_philo	*p;

	p = (t_philo *)per;
	while (!p->rules->ready)
		continue ;
	if (!(p->id % 2))
		ft_sleep(p->rules->t2e * 0.9 + 1);
	while (!p->rules->game_over)
	{
		eat(p);
		sleep_think(p);
	}
	return (NULL);
}