/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:39:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/22 17:12:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_data *d, t_philo *p, int i)
{
	p = (t_philo *)malloc(sizeof(t_philo) * d->nb_philo);
	if (!p)
		return (0);
	d->philos = p;
	d->threads = (pthread_t *)malloc(sizeof(pthread_t) * d->nb_philo);
	if (!d->threads)
		return (free(p), 0);
	pthread_mutex_init(&d->print, NULL);
	while (++i < d->nb_philo)
		pthread_mutex_init(&p[i].fork, NULL);
	ft_time();
	i = -1;
	while (++i < d->nb_philo)
	{
		p[i].id = i;
		p[i].time_lmeal = 0;
		p[i].meal_eaten = 0;
		p[i].g_status = 1;
		p[i].data = d;
	}
	return (1);
}