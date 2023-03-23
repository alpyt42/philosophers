/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:59:26 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/23 20:27:21 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	get_time(void)
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
		begin = get_time();
	return (get_time() - begin);
}

void	ft_sleep(long long time)
{
	long long	to_time;

	to_time = get_time() + time;
	while (get_time() < to_time)
		usleep(100);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_print(t_philo *p, char *action)
{
	int	g_status;

	pthread_mutex_lock(&p->data->print);
	g_status = p->data->g_status;
	p->g_status = g_status;
	if (g_status && !ft_strncmp(action, EAT, 9))
	{
		p->time_lmeal = ft_time();
		p->meal_eaten++;
	}
	if (g_status)
		printf("%lld %d %s\n", ft_time(), p->id + 1, action);
	pthread_mutex_unlock(&p->data->print);
	return (g_status);
}
