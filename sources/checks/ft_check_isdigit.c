/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:29:04 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 18:13:20 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_isdigit(int argc, char **argv )
{
	int		i;
	long	num;

	i = 1;
	while (argv[i] && i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < 0 || num > 2147483647)
		{
			ft_print_error();
			return (0);
		}
		if (ft_has_digit(argv[i]) == 0)
		{
			ft_print_error();
			return (0);
		}
		i++;
	}
	return (1);
}
