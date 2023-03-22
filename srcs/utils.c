/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:59:26 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/22 17:04:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_timestamp(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		return(0);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long long	ft_time(void)
{
	static long long	begin = 0;

	if (!begin)
		begin = ft_timestamp();
	return (ft_timestamp() - begin);
}
