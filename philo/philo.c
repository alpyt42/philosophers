/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/10 22:38:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	display_error()
{
	printf("\033[1;31mError\033[0m\n\n");
	// exit(EXIT_FAILURE);
	return(NULL);
}

int	main(void)
{
	// t_philo philo;
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &display_error, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &display_error, NULL) != 0)
		return (1);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}