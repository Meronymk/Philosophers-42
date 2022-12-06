/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:17:28 by krochefo          #+#    #+#             */
/*   Updated: 2022/12/06 14:05:57 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

//═══════𖠁 Color 𖠁════════//
# define YEL  "\x1B[33m"
# define WHT  "\x1B[37m"

//═════𖠁 Structures 𖠁═════//
typedef struct philo_rules
{
	unsigned int	philo_total;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_times_each_philosopher_must_eat;
	long int		start_time;
	bool			someone_died;
	bool			meal_done;
	pthread_mutex_t	meal_lock[1];
	pthread_mutex_t	dead_queue[1];
	pthread_mutex_t	forks[201];
	pthread_t		thread_id[201];
}	t_rules;

typedef struct philo_entity
{
	int				id;
	bool			has_fork;
	bool			is_eating;
	bool			is_sleeping;
	bool			is_thinking;
	long			time_last_meal;
	int				nb_meal;
	t_rules			*rules;
}	t_philo;

//═════𖠁 philosopher.c 𖠁═════//
void			*entity_routine(void *arg);
void			eating_cycle(t_philo *philo);
void			left_right_hands(t_philo *philo);
void			lone_philo(t_philo *philo);
//════════𖠁 init.c 𖠁═════════//
void			philo_init(t_philo *philo, t_rules *rules);
void			rules_init(char **argv, t_rules *rules);
void			destroy_all_mutex(t_rules *rules);
void			time_cycle(unsigned int time);
//════════𖠁 utils.c 𖠁════════//
int				console_message(t_philo *philo);
long int		get_time(void);
void			butler(t_philo *philo);
int				check_meal(t_philo *philo);
void			meal_lock(t_philo *philo);
//═══════𖠁 parsing.c 𖠁═══════//
int				parsing(int argc, char **argv);
int				error_message(int i);
int				check_value(char **argv);
int				check_alpha(char **argv);
int				check_null(char **argv);
//═════𖠁 assignments.c 𖠁═════//
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
unsigned int	int_to_unsigned(int i);
unsigned int	atou(char *str);
int				ft_strlen(char *str);

#endif
