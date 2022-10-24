/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:10:45 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/13 15:10:45 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

long long int	my_atoli(const char *str)
{
	long long int	num;
	int				sign;

	sign = 1;
	num = 0;
	while (is_white_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10;
		num = num + (*str - '0');
		str++;
		if ((sign * num) > 4294967295)
			return (4294967295);
		if ((sign * num) < -4294967295)
			return (-4294967295);
	}
	return (sign * num);
}
