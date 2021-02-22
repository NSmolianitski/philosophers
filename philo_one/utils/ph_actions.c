/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:16:10 by pkentaur          #+#    #+#             */
/*   Updated: 2021/02/18 17:16:12 by pkentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ph_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data.forks[philo->lfork]);
		action_print(philo, 1);
		pthread_mutex_lock(&philo->data.forks[philo->rfork]);
		action_print(philo, 1);
	}
	else
	{
		pthread_mutex_lock(&philo->data.forks[philo->rfork]);
		action_print(philo, 1);
		pthread_mutex_lock(&philo->data.forks[philo->lfork]);
		action_print(philo, 1);
	}
}

void	ph_eat(t_philo *philo)
{
	action_print(philo, 2);
	philo->etime = get_time();
	++philo->ecount;
//	printf("I am %d, I ate %d times\n", philo->id, philo->ecount);
	ph_usleep(philo->data.tte);
	philo->eatperm = 0;
	pthread_mutex_unlock(&philo->data.forks[philo->rfork]);
	pthread_mutex_unlock(&philo->data.forks[philo->lfork]);
}

void	ph_sleep(t_philo *philo)
{
	action_print(philo, 3);
	ph_usleep(philo->data.tts);
}

void	ph_think(t_philo *philo)
{
	action_print(philo, 4);
}
