/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:35:11 by user42            #+#    #+#             */
/*   Updated: 2020/10/23 12:38:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void			ft_end_message(t_philo *philo, char *message)
{
	if (philo->global->die == 0)
	{
		sem_wait(philo->global->talk);
		philo->global->die += 1;
		ft_printmsg(philo, message);
	}
}

void			*monitoring(void *args)
{
	t_philo		*philo;
	t_global	*global;

	philo = (t_philo *)args;
	global = philo->global;
	while (global->die == 0)
	{
		if (sem_wait(philo->lock) == 0)
		{
			if (ft_get_time(philo->last_eat) > global->time_to_die)
			{
				ft_end_message(philo, "died");
				sem_post(global->lock);
			}
			sem_post(philo->lock);
		}
		ft_usleep(1);
	}
	return (args);
}

void			*ft_gbl_monitoring(void *args)
{
	t_global	*global;
	int			i;

	i = -1;
	global = (t_global*)args;
	if (global->nb_of_meals != -1)
	{
		while (++i < global->nb_philos)
			sem_wait(global->philos[i].lockeat);
		global->die += 1;
		sem_post(global->lock);
	}
	return (global);
}
