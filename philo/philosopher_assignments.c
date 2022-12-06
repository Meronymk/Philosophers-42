/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_assignments.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:25:07 by krochefo          #+#    #+#             */
/*   Updated: 2022/10/25 19:14:02 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	int_to_unsigned(int i)
{
	unsigned int	k;

	k = i;
	if (i < 0)
		k = -i;
	return (k);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
		sign *= -1;
	}
	while (ft_isdigit(*str))
	{
	result = result * 10;
	result += (*str++ - '0');
	}
	return (sign * result);
}

unsigned int	atou(char *str)
{
	return (int_to_unsigned(ft_atoi(str)));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
