/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:33:58 by user42            #+#    #+#             */
/*   Updated: 2020/10/23 12:33:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	ft_end_message(t_philo *philo, char *message)
{
	if (philo->global->die == 0)
	{
		pthread_mutex_lock(&philo->global->talk);
		philo->global->die += 1;
		ft_printmsg(philo, message);
	}
}

void	*monitoring(void *args)
{
	t_philo			*philo;
	t_global		*global;

	philo = (t_philo *)args;
	global = philo->global;
	while (global->die == 0)
	{
		if (pthread_mutex_lock(&philo->lock) == 0)
		{
			if (ft_get_time(philo->last_eat) > global->time_to_die)
				ft_end_message(philo, "died");
			pthread_mutex_unlock(&philo->lock);
		}
		ft_usleep(1);
	}
	return (args);
}

void	ft_gbl_monitoring(t_global *global)
{
	while (global->die == 0)
		if (global->eats == global->nb_philos && global->nb_of_meals > 0)
		{
			global->die += 1;
			return ;
		}
}
