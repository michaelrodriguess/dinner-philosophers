/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_allfull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:40:02 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 17:25:54 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_check_allfull(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->rule->number_of_philosophers)
	{
		if (ft_check_isfull(philos) == 1)
			return (1);
		i++;
	}
	return (0);
}
