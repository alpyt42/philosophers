/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:06:34 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/21 20:31:04 by ale-cont         ###   ########.fr       */
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
		return (0);
	return (0);
}
