/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:36:29 by user42            #+#    #+#             */
/*   Updated: 2020/10/23 12:36:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <inttypes.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct				s_philo
{
	int						id;
	int						eat;
	long int				last_eat;
	sem_t					*lock;
	struct s_global			*global;
}							t_philo;

typedef struct				s_global
{
	int						nb_philos;
	int						threads;
	int						die;
	long int				time_to_die;
	long int				time_to_eat;
	long int				time_to_sleep;
	long int				t_start;
	int						nb_of_meals;
	int						eats;
	sem_t					*talk;
	sem_t					*keys;
	t_philo					*philos;
}							t_global;

long int					ft_get_time(long int type);
void						ft_putnbr(int n);
void						ft_putstr(char *str, int fd);
void						ft_putchar(char caract, int fd);
int							ft_check(char **str);
int							ft_isnum(char *str);
long long					ft_atoi(const char *str);
void						ft_start(void *global);
void						ft_usleep(long int time);
char						*ft_itoa(long int n);
void						*ft_calloc(size_t count, size_t size);
size_t						ft_strlen(char *str);
char						*ft_completestr(char *str, char *src);
void						ft_messages(t_philo *philo, char *message);
void						ft_messages2(t_philo *philo, char *message);
int							ft_clear_all(t_global *global);
void						*monitoring(void *args);
void						ft_gbl_monitoring(t_global *global);
sem_t						*ft_launch_sem(char *array, int i);
void						ft_init_philos(t_global *global);
int							ft_init_gbl(char **str, int ac, t_global *global);
char						*ft_itoa(long int n);
void						ft_end_message(t_philo *philo, char *message);
void						ft_printmsg(t_philo *philo, char *message);

#endif
