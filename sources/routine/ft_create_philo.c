/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:44:48 by microdri          #+#    #+#             */
/*   Updated: 2023/02/04 11:23:29 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_create_philos(t_philo *philos)
{
	int	i;

	i = 0;
	philos->rule->time_update = ft_get_time();
	while (i < philos->rule->number_of_philosophers)
	{
		pthread_mutex_lock(&philos->m_time_of_last_meal);
		philos[i].time_of_last_meal = ft_time_formated(&philos[i]);
		pthread_mutex_unlock(&philos->m_time_of_last_meal);
		if (pthread_create(&philos[i].philo, 0, &ft_routine, &philos[i]) != 0)
			return (ft_print_error());
		i++;
	}
	ft_monitoring_isdead(philos);
	i = 0;
	while (i < philos->rule->number_of_philosophers)
	{
		if (pthread_join(philos[i].philo, NULL) != 0)
			return (ft_print_error());
		i++;
	}
	return (0);
}
