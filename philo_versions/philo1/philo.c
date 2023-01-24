/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/23 18:51:35 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	status_thread(t_rules *r, t_philo *p)
{
	while (!r->ready)
		continue ;
	while (!r->game_over)
		if (check_death(p) || check_meal(p))
				r->game_over = 1;
	if (r->all_ate)
	{
		ft_sleep(3 * r->nb_philo);
		pthread_mutex_lock(p->rules->writing);
		printf("Everyone has eaten %d meal(s)", r->max_meal);
		pthread_mutex_unlock(p->rules->writing);
	}
	return (0);
}

int	launch_threads(t_rules *r, t_philo *p)
{
	int	i;
	
	i = -1;
	while (++i < r->nb_philo)
	{
		p[i].rf = p[(i + 1) % r->nb_philo].lf;
		if (pthread_create(&p[i].life, NULL, &routine, &p[i]))
			return (error("\nIssue when creating threads for each philos\n", r, p));
	}
	i = -1;
	r->start = time_get();
	while(++i < r->nb_philo)
	{
		p[i].thread_start = r->start;
		p[i].time_last_meal = r->start;
	}
	r->ready = 1;
	// printf("test2");
	return (0);
}

int	philo(t_rules *r)
{
	t_philo	*p;
	
	p = malloc(sizeof(t_philo) * r->nb_philo);
	if (!p)
		return (error("Issue when malloc philo", r, p));
	init_philo(r, p);
	// printf("test1");
	if (launch_threads(r, p))
		return (error("Threads Failed", r, p));
	status_thread(r, p);
	// free_thread(r, p);
	return (0);
}