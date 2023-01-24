/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_situation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:23:34 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/23 23:28:34 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *p)
{
	int	i;
	
	i = -1;
	while (++i < p->rules->nb_philo)
		if (time_get() - p->time_last_meal >= p->rules->t2d)
			return (dead(p));
	return (0);
}

int	check_meal(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->rules->nb_philo)
		if (p[i].meal_eaten != p->rules->max_meal)
			return (0) ;
	p->rules->all_ate = 1;
	return (1);
}
