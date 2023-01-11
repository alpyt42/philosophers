/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:45:33 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/11 18:37:18 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_body(t_philo *p)
{
	
}

int	eat(t_philo *p)
{
	pthread_mutex_lock(p->lf);
	p_rout(p, FORK);
	pthread_mutex_lock(p[p->id + 1].lf);
	p_rout(p, FORK);
}

int	think(t_philo *p)
{
	
}

int	sleep(t_philo *p)
{
	
}


int	*routine(void *per)
{
	t_philo	*p;

	p = (t_philo *)per;
}