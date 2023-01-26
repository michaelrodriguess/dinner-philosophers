/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_isdead.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:09 by microdri          #+#    #+#             */
/*   Updated: 2023/01/26 17:26:15 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_monitoring_isdead(t_philo *philos)
{
	int i;

	while (philos->rule->flag_someone_die == 1 && philos->times_that_eat < philos->rule->number_each_philo_eat)
	{
		i = 0;
		while(i < philos->rule->number_of_philosophers)
		{
			if((ft_time_formated(&philos[i]) - philos[i].time_of_last_meal) > philos->rule->time_to_die)
			{
				philos->rule->flag_someone_die = 0;
				printf("%ld\t%d\tdied\n", ft_time_formated(philos), philos[i].pid);
				break ;
			}
			i++;
		}
	}
}
