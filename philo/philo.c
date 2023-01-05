/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/05 17:23:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_error(t_data *var, char *error)
{
	(void)var;
	printf("\033[1;31mError\033[0m\n%s\n", error);
	exit(EXIT_FAILURE);
}

int	ft_error(int argc, char **argv)
{
	
}

int	main(int argc, char **argv)
{
	t_data var;
	
	(void)var;
	if (argc < 5 || argc > 6)
		display_error(&var, "Wrong number of arguments");
	else
		ft_error(argc, argv);
	
}