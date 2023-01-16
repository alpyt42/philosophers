/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/16 16:51:10 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_threads(t_rules *r, t_philo *p)
{
	int	i;
	
	i = 0;
	while (++i < r->num)
	{
		p[i].rf = p[(i + 1) % r->num].lf;
		if (pthread_create(&p[i].life, NULL, &routine, &p[i]))
			return (error("\nIssue when creating threads for each philos\n", r, p));
	}
	i = -1;
	r->start = time_get();
	while(++i < r->num)
	{
		p[i].thread_start = r->start;
		p[i].meal = r->start;
	}
	r->ready = 1;
	return (0);
}

int	philo(t_rules *r)
{
	t_philo	*p;
	
	p = malloc(sizeof(t_philo) * r->num);
	if (!p)
		return (error("Issue when malloc philo", r, p));
	init_philo(r, p);
	if (launch_threads(r, p))
		return (error("Threads Failed", r, p));
	// status_thread(r, p);
	// free_thread(r, p);
	return (0);
}