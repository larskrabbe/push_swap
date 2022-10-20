/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:02:44 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/13 15:59:21 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack	*look_for_value(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value == value)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->value == value)
		return (tmp);
	else
		return (NULL);
}

t_stack	*is_smallest(t_stack *stack, t_both *top)
{
	t_stack	*tmp;
	t_stack	*smallest;

	if (stack == NULL)
		my_error("EMPTY STACK in is_smallest function", top);
	smallest = stack;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value < smallest->value)
			smallest = tmp;
		tmp = tmp->next;
	}
	if (tmp->value < smallest->value)
		smallest = tmp;
	return (smallest);
}

t_stack	*is_biggest(t_stack *stack, t_both *top)
{
	t_stack	*tmp;
	t_stack	*biggest;

	if (stack == NULL)
		my_error("EMPTY STACK in is_biggest function", top);
	biggest = stack;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value > biggest->value)
			biggest = tmp;
		tmp = tmp->next;
	}
	if (tmp->value > biggest->value)
		biggest = tmp;
	return (biggest);
}

int	is_small_big(t_stack *stack_a)
{
	t_stack	*tmp;
	short	end;

	end = 0;
	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		if (tmp->value > tmp->next->value)
		{
			if (end == 0)
				end = 1;
			else
				return (-1);
		}	
		tmp = tmp->next;
	}
	if (tmp->value > tmp->next->value)
	{
		if (end == 0)
			return (1);
		else
			return (-1);
	}
	return (1);
}

int	stack_length(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	if (stack == NULL)
		return (0);
	len = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	len++;
	return (len);
}
