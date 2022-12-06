/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:55:46 by krochefo          #+#    #+#             */
/*   Updated: 2022/12/06 14:16:10 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*entity_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	left_right_hands(philo);
	while (1)
	{
		if (philo->rules->someone_died == true)
			break ;
		else
		{
			philo->is_thinking = false;
			eating_cycle(philo);
			philo->has_fork = false;
			philo->is_eating = false;
			philo->is_sleeping = true;
			console_message(philo);
			time_cycle(philo->rules->time_to_sleep);
			philo->is_sleeping = false;
			philo->is_thinking = true;
			console_message(philo);
		}
	}
	return (NULL);
}

void	left_right_hands(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
}

void	lone_philo(t_philo *philo)
{
	philo->has_fork = false;
	usleep(1000 * philo->rules->time_to_die);
	philo->rules->someone_died = true;
	console_message(philo);
}

void	eating_cycle(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->id % \
	philo->rules->philo_total]);
	philo->has_fork = true;
	console_message(philo);
	if (philo->rules->philo_total > 1)
	{
		pthread_mutex_lock(&philo->rules->forks[philo->id - 1]);
		philo->time_last_meal = get_time();
		console_message(philo);
		philo->is_eating = true;
		philo->has_fork = false;
		console_message(philo);
		time_cycle(philo->rules->time_to_eat);
		pthread_mutex_unlock(&philo->rules->forks[philo->id % \
			philo->rules->philo_total]);
		pthread_mutex_unlock(&philo->rules->forks[philo->id - 1]);
		meal_lock(philo);
	}
	else
		lone_philo(philo);
}

int	main(int argc, char **argv)
{
	t_rules			rules;
	t_philo			philo[201];
	unsigned int	i;

	i = 0;
	if (parsing(argc, argv) == 0)
	{
		rules_init(argv, &rules);
		philo_init(&philo[0], &rules);
		while (i < rules.philo_total)
		{
			pthread_create(&rules.thread_id[i],
				NULL, &entity_routine, &philo[i]);
			i++;
		}
		butler(philo);
		i = 0;
		while (i < rules.philo_total)
		{
			pthread_join(rules.thread_id[i], NULL);
			i++;
		}
		destroy_all_mutex(&rules);
	}
	return (0);
}
