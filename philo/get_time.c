/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:56:11 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/11 16:16:14 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_get(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		return(0);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

