/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/23 23:53:44 by ale-cont         ###   ########.fr       */
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
	long int	time;

	time = -1;
	time = time_get() - p->rules->start;
	if (time >= 0 && time <= 2147483647 && !check_death(p))
		printf("[%ldms] Philo %d %s\n", time, p->id + 1, str);
}