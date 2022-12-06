/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:56:20 by krochefo          #+#    #+#             */
/*   Updated: 2022/11/29 15:59:28 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv)
{
	if (check_value(argv) == 0)
		return (error_message(2));
	if (check_alpha(argv) == 0)
		return (error_message(3));
	if (check_null(argv) == 0)
		return (error_message(5));
	if (argc <= 4)
		return (error_message(1));
	if (argc < 5 && argv[4][0])
		return (error_message(1));
	if (argc > 6)
		return (error_message(1));
	if (ft_atoi(argv[1]) == 0)
		return (error_message(4));
	if (ft_atoi(argv[1]) >= 201)
		return (error_message(6));
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0)
		return (error_message(7));
	return (0);
}

int	error_message(int i)
{
	if (i == 1)
		printf("%sIndexError: invalid number of arguments%s\n", YEL, WHT);
	if (i == 2)
		printf("%sValueError: numbers must be a positive value%s\n", YEL, WHT);
	if (i == 3)
		printf("%sSyntaxError: arguments must be numbers%s\n", YEL, WHT);
	if (i == 4)
		printf("%sIndexError: number of philo must not be 0%s\n", YEL, WHT);
	if (i == 5)
		printf("%sTypeError: arguments must not be empty%s\n", YEL, WHT);
	if (i == 6)
		printf("%sValueError: number of philo over limit%s\n", YEL, WHT);
	if (i == 7)
		printf("%sValueError: number over maximum long int value%s\n", YEL, WHT);
	return (1);
}

int	check_value(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_alpha(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z')
				|| (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_null(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
