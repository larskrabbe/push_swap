/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:23:04 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/22 16:36:47 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack	*rotate(t_stack **stack)
{
	if(*stack == NULL)
		my_error("Try to rotate a empty stack\n");
	if(*stack == (*stack)->next)
		my_error("Try to rotate a Stack with only one structure\n");
	*stack = (*stack)->next;
	return(*stack);
}

t_stack	*reverse_rotate(t_stack **stack)
{
	if(*stack == NULL)
		my_error("Try to reverse rotate a empty stack\n");
	if(*stack == (*stack)->next)
		my_error("Try to reverse rotate a Stack with only one structure\n");
	*stack = (*stack)->back;
	return(*stack);
}