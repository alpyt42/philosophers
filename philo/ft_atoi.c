/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:51:48 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/11 13:41:20 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t					i;
	int						sign;
	unsigned long long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		nb = nb * 10 + str[i++] - 48;
	}
	if (nb > LLONG_MAX || sign < 0)
		return (0);
	return (sign * nb);
}

