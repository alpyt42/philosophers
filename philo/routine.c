/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:45:33 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/18 17:13:41 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_philo *p)
{
	p_rout(p, DEAD);
	p->rules->game_over = 1;
	p->dead = 1;
	pthread_mutex_unlock(p->lf);
	pthread_mutex_unlock(p->rf);
	return (1);
}

static void	eat(t_philo *p)
{
	pthread_mutex_lock(p->lf);
	p_rout(p, FORK);
	pthread_mutex_lock(p->rf);
	p_rout(p, FORK);
	p->time_last_meal = time_get();
	ft_sleep(p->rules->t2e);
	p_rout(p, EAT);
	p->meal_eaten++;
	pthread_mutex_unlock(p->lf);
	pthread_mutex_unlock(p->rf);
}

static void	sleep_think(t_philo *p)
{
	ft_sleep(p->rules->t2s);
	p_rout(p, SLEEP);
	p_rout(p, THINK);
}

void	*routine(void *per)
{
	t_philo	*p;

	p = (t_philo *)per;
	while (!p->rules->ready)
		continue ;
	// if (!p->id)
	// 	ft_sleep(1);
	while (!p->rules->game_over)
	{
		eat(p);
		sleep_think(p);
	}
	return (NULL);
}