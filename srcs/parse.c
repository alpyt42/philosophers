/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:19:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/21 20:33:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	valid_data(t_data *d)
{
	if (d->nb_philo < 1)
		return (printf("Error 'parsing' (Nb Philos must be above 1)\n"));
	if (d->t2d < 1)
		return (printf("Error 'parsing' (Time to Death must be above 1)\n"));
	if (d->t2e < 1)
		return (printf("Error 'parsing' (Time to Eat must be above 1)\n"));
	if (d->t2s < 1)
		return (printf("Error 'parsing' (Time to Sleep must be above 1)\n"));
	if (d->max_meal < 1 && d->argc == 6)
		return (printf("Error 'parsing' (Nb Max_Meal must be above 1)\n"));
	return (1);
}

int	parse(t_data *d, t_philo **p)
{
	if (d->argc == 5 || d->argc == 6)
	{
		d->g_status = 1;
		d->nb_philo = ft_atoi(d->argv[1]);
		d->t2d = ft_atoi(d->argv[2]);
		d->t2e = ft_atoi(d->argv[3]);
		d->t2s = ft_atoi(d->argv[4]);
		if (d->argc == 6)
			d->max_meal = ft_atoi(d->argv[5]);
		else
			d->max_meal = -1;
		if (valid_data(d))
			return (0);
		d->threads = NULL;
		*p = NULL;
		return (1);
	}
	else
	{
		printf("Error Parsing : Number of Arguments\n");
		printf("./philo nb_philos time_die time_eat time_sleep [nb_meal]\n");
	}
	return (0);
}
