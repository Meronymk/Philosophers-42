/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:41:59 by krochefo          #+#    #+#             */
/*   Updated: 2022/12/06 14:15:26 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	t;
	long int		time;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (time);
}

int	console_message(t_philo *philo)
{
	long int		time;
	unsigned int	i;

	i = 0;
	if (philo->rules->someone_died == true)
		return (0);
	pthread_mutex_lock(&philo->rules->dead_queue[0]);
	time = (get_time() - philo->rules->start_time);
	if (philo->rules->someone_died == false)
	{
		if (philo->has_fork == true && philo->rules->someone_died == false)
			printf("%lu %i has taken a fork\n", time, philo->id);
		if (philo->is_eating == true && philo->rules->someone_died == false)
			printf("%lu %i is eating\n", time, philo->id);
		if (philo->is_sleeping == true && philo->rules->someone_died == false)
			printf("%lu %i is sleeping\n", time, philo->id);
		if (philo->is_thinking == true && philo->rules->someone_died == false)
			printf("%lu %i is thinking\n", time, philo->id);
	}
	pthread_mutex_unlock(&philo->rules->dead_queue[0]);
	return (0);
}

void	butler(t_philo *philo)
{
	int				i;
	long int		time;

	i = 0;
	while (1)
	{
		check_meal(philo);
		if (philo->rules->meal_done == true)
			break ;
		if (get_time() - philo[i].time_last_meal >= philo[i].rules->time_to_die)
		{
			time = (get_time() - philo->rules->start_time);
			printf("%lu %i died\n", time, philo[i].id);
			philo->rules->someone_died = true;
			break ;
		}
		i = (i + 1) % philo->rules->philo_total;
	}
}

int	check_meal(t_philo *philo)
{
	unsigned int	i;
	unsigned int	k;

	k = 0;
	i = 0;
	if (philo->rules->meal_done == true)
		return (0);
	while (i != philo->rules->philo_total)
	{
		if (philo[i].nb_meal == \
			(int)philo->rules->number_of_times_each_philosopher_must_eat)
		k++;
		if (k == philo->rules->philo_total)
		{
			philo->rules->someone_died = true;
			philo->rules->meal_done = true;
			printf("All philosophers ate %i time(s)\n", \
				philo->rules->number_of_times_each_philosopher_must_eat);
			return (0);
		}
		i++;
	}
	return (0);
}

void	meal_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->meal_lock[0]);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->rules->meal_lock[0]);
}
