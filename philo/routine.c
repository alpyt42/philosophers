/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:45:33 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/17 19:53:20 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	dead_body(t_philo *p)
// {
	
// }

static void	eat(t_philo *p)
{
	pthread_mutex_lock(p->lf);
	p_rout(p, FORK);
	pthread_mutex_lock(p->rf);
	p_rout(p, FORK);
	p->meal = time_get();
	ft_sleep(p->rules->t2e);
	p_rout(p, EAT);
	p->meal_eaten++;
	pthread_mutex_destroy(p->lf);
	pthread_mutex_destroy(p->rf);
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
	// while (!p->rules->ready)
	// 	continue ;
	while (!p->rules->game_over)
	{
		eat(p);
		sleep_think(p);
	}
	return (NULL);
}