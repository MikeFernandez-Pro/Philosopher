/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:34:48 by user42            #+#    #+#             */
/*   Updated: 2020/10/23 12:34:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

int			ft_clear_all(t_global *global)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < global->nb_philos)
	{
		tmp = ft_itoa(i);
		sem_unlink(tmp);
		free(tmp);
	}
	sem_unlink("KEYS");
	sem_unlink("TALK");
	free(global->philos);
	return (1);
}

long int	ft_get_time(long int type)
{
	long int		time;
	struct timeval	te;

	gettimeofday(&te, NULL);
	if (type == 0)
		time = te.tv_sec * 1000LL + te.tv_usec / 1000;
	else
		time = (te.tv_sec * 1000LL + te.tv_usec / 1000) - type;
	return (time);
}

void		ft_usleep(long int time)
{
	long int	start;

	start = ft_get_time(0);
	while (ft_get_time(start) < time)
		usleep(1);
}
