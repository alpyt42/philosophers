/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/11 17:49:27 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_threads(t_philo *p, t_rules *r)
{
	int	i;
	
	i = 0;
	while (++i < r->num)
		if (pthread_create(&p[i].life, NULL, &routine, NULL));
			return (error("Issue when creating threads for each philos", r, p));
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
	return (0);
}