/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:54:03 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/17 20:01:01 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_rules *r, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < r->num)
	{
		p[i].id = i;
		p[i].dead = 0;
		p[i].meal_eaten = 0;
		p[i].thread_start = 0;
		p[i].meal = 0;
		p[i].lf = &r->fork[i];
		p[i].rf = 0;
		p[i].rules = r;
	}
	return (0);
}

static int	init_mutex(t_rules *r)
{
	int	i;
	
	i = -1;
	r->death = malloc(sizeof(pthread_mutex_t));
	if (!r->death)
		return (error("Error when malloc (death)", r, 0));
	r->fork = malloc(sizeof(pthread_mutex_t) * r->num);
	if (!r->fork)
		return (error("Error when malloc (fork)", r, 0));
	if (pthread_mutex_init(r->death, NULL))
		return (error("Error when creating mutex (death)", r, 0));
	while (++i < r->num)
		if (pthread_mutex_init(&r->fork[i], NULL))
			return (error("Error when creating mutex (fork)", r, 0));
	return (0);
}

static int	init_rules(t_rules *r, char **ag)
{
	int	mutex;

	mutex = -1;
	r->num = ft_atoi(ag[1]);
	r->t2d = ft_atoi(ag[2]);
	r->t2e = ft_atoi(ag[3]);
	r->t2s = ft_atoi(ag[4]);
	r->max_meal = -1;
	r->check_meal = 0;
	r->start = 0;
	r->ready = 0;
	if (ag[5])
	{
		r->check_meal = 1;
		r->max_meal = ft_atoi(ag[5]);
	}
	if (r->num > 0)
		mutex = init_mutex(r);
	// printf("mutex %d\n", mutex);
	// printf("r->num %d\n", r->num);
	// printf("r->t2d %d\n", r->t2d);
	// printf("r->t2e %d\n", r->t2e);
	// printf("r->t2s %d\n", r->t2s);
	// printf("r->max_meal %d\n", r->max_meal);
	return (mutex || r->num == 0 || r->t2d == 0 || r->t2e == 0 
			|| r->t2s == 0 || r->max_meal == 0);
}

int	main(int ac, char **ag)
{
	t_rules	r;

	if ((ac != 5 && ac != 6))
		return (error("Wrong Arguments\n", 0, 0));
	if (init_rules(&r, ag))
		return (error("Failed when Initializing\n", &r, 0));
	// r.start = time_get();
	// printf("[%ld]", r.start);
	// if (philo(&r))
	// {
	// 	printf("coucou");
	// 	return (EXIT_FAILURE);
	// }
	return (EXIT_SUCCESS);
}
