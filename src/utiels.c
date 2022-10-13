/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:31:33 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/13 16:08:39 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack == NULL)
	{
		printf("Empty stack\n");
		return ;
	}
	tmp = stack;
	printf("%i ", tmp->value);
	while (tmp->next != stack)
	{
		tmp = tmp->next;
		printf("%i ", tmp->value);
		i++;
	}
	printf("\n");
}

void	print_stack_index(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack == NULL)
	{
		ft_printf("Empty stack\n");
		return ;
	}
	tmp = stack;
	ft_printf("%i ", tmp->index);
	while (tmp->next != stack)
	{
		tmp = tmp->next;
		ft_printf("%i ", tmp->index);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_reverse(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack == NULL)
	{
		ft_printf("Empty stack\n");
		return ;
	}
	tmp = stack;
	ft_printf("%i ", tmp->value);
	while (tmp->back != stack)
	{
		tmp = tmp->back;
		ft_printf("%i ", tmp->value);
		i++;
	}
	printf("\n");
}

void	my_error(char *message, t_both *top)
{
	free_two_stacks(top);
	if (BETTERERROR == 0)
		write(2, "Error\n", 6);
	else
		ft_printf(" \033[1;31m Error : %s\033[1;0m\n", message);
	exit(0);
}
