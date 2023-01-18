/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/18 18:02:42 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str, t_rules *r, t_philo *p)
{
	if (r)
	{
		if (r->fork)
			free(r->fork);
		if (r->writing)
			free(r->writing);
	}
	if (p)
		free(p);
	printf("%s", str);
	return (1);
}

void	p_rout(t_philo *p, char *str)
{
	pthread_mutex_lock(p->rules->writing);
	printf("[%ld] %d %s\n", time_get() - p->rules->start, p->id + 1, str);
	pthread_mutex_unlock(p->rules->writing);
}