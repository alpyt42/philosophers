/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:52 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/27 22:16:21 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	p_sleep(t_philo *p)
{
	int	g_status;

	g_status = ft_print(p, SLEEP);
	if (g_status)
		ft_sleep(p->data->t2s);
	return (g_status);
}

static int	p_eat(t_philo *p)
{
	int	g_status;

	pthread_mutex_lock(&p->fork);
	if (!ft_print(p, FORK))
	{
		pthread_mutex_unlock(&p->fork);
		return (2);
	}
	if (p->data->nb_philo > 1)
		pthread_mutex_lock(&p->data->philos[(p->id + 1)
			% p->data->nb_philo].fork);
	else
	{
		pthread_mutex_unlock(&p->fork);
		return (3);
	}
	if (!ft_print(p, FORK))
		return (4);
	g_status = ft_print(p, EAT);
	if (g_status)
		ft_sleep(p->data->t2e);
	return (g_status);
}

void	life(t_philo *p)
{
	int	eat;

	while ((p->meal_eaten != p->data->max_meal
	|| p->data->max_meal == -1) && p->g_status)
	{
		eat = 1;
		if (p->id % 2 == 0)
			usleep(p->data->nb_philo * 100);
		eat = p_eat(p);
		if (eat > 1 || !eat)
		{
			if (!eat || eat == 4)
			{
				pthread_mutex_unlock(&p->fork);
				pthread_mutex_unlock(&p->data->philos[(p->id + 1)
					% p->data->nb_philo].fork);
			}
			break ;
		}
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(&p->data->philos[(p->id + 1)
			% p->data->nb_philo].fork);
		if (!ft_print(p, THINK))
			break ;
		if (!p_sleep(p))
			break ;
	}
}
