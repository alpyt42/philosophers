/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:06:34 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/22 17:12:26 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	d;
	t_philo	*p;

	d.argv = argv;
	d.argc = argc;
	(void)p;
	if (!parse(&d, &p))
		return (1);
	if (!init(&d, p, -1))
		return (2);
	
	return (0);
}
