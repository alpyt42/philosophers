/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/11 16:48:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_threads(t_philo *p, t_rules *r)
{
	
}

int	philo(t_rules *r)
{
	t_philo	*p;
	
	p = malloc(sizeof(t_philo) * r->num);
	if (!p || init_philo(r, p))
		return (error("Issue when initiating philos", r, p));
	if (launch_threads(r, p))
		return (error("Threads Failed", r, p));
	return (0);
}