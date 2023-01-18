/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_situation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:23:34 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/18 17:58:42 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *p)
{
	pthread_mutex_lock(p->rules->death);
	if (time_get() - p->time_last_meal >= p->rules->t2d)
		return (dead(p));
	pthread_mutex_unlock(p->rules->death);
	return (0);
}

int	check_meal(t_philo *p)
{
	(void)p;
	return (0);
}
