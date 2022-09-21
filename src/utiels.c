/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:31:33 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/21 17:52:52 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
		ft_printf("%i ",tmp->value);
	while(tmp->next != stack)
		{
			tmp = tmp->next;
			ft_printf("%i ",tmp->value);

		}
	ft_printf("\n");
}

void	my_error(char *message)
{
	printf("\n\033[1;31m%s\033[1;0m\n",message);
	exit(0);
}
