/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:22:33 by krochefo          #+#    #+#             */
/*   Updated: 2022/12/06 14:31:03 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_rules *rules)
{
	unsigned int	i;

	i = 0;
	while (i < rules->philo_total)
	{
		philo[i].rules = rules;
		philo[i].has_fork = true;
		philo[i].is_eating = false;
		philo[i].is_sleeping = false;
		philo[i].is_thinking = false;
		philo[i].time_last_meal = get_time();
		philo[i].id = i + 1;
		philo[i].nb_meal = 0;
		pthread_mutex_init(&rules->forks[i], NULL);
		pthread_mutex_init(&rules->dead_queue[i], NULL);
		pthread_mutex_init(&rules->meal_lock[i], NULL);
		i++;
	}
	philo[i].id = 0;
}

void	rules_init(char **argv, t_rules *rules)
{
	rules->start_time = get_time();
	rules->philo_total = atou(argv[1]);
	rules->time_to_die = (atou(argv[2]) * 1000);
	rules->time_to_eat = (atou(argv[3]) * 1000);
	rules->time_to_sleep = (atou(argv[4]) * 1000);
	if (argv[5])
		rules->number_of_times_each_philosopher_must_eat = atou(argv[5]);
	else
		rules->number_of_times_each_philosopher_must_eat = 32767;
	rules->someone_died = false;
	rules->meal_done = false;
}

void	destroy_all_mutex(t_rules *rules)
{
	pthread_mutex_destroy(rules->forks);
	pthread_mutex_destroy(rules->dead_queue);
	pthread_mutex_destroy(rules->meal_lock);
}

void	time_cycle(unsigned int time)
{
	long int	timenow;

	timenow = get_time();
	while (get_time() - timenow <= time / 1000)
	{
		usleep(500);
	}
}
