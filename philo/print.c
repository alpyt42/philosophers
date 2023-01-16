/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/16 18:08:35 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str, t_rules *r, t_philo *p)
{
	if (r)
	{
		if (r->fork)
			free(r->fork);
		if (r->death)
			free(r->death);
	}
	if (p)
		free(p);
	printf("%s", str);
	return (1);
}

void	p_rout(t_philo *p, char *str)
{
	pthread_mutex_lock(p->rules->death);
	printf("%d %s", p->id, str);
	pthread_mutex_unlock(p->rules->death);
}