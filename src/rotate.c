/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:23:04 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/10 08:51:23 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack	*rotate(t_stack **stack ,t_both *top)
{
	if(*stack == NULL)
		my_error("Try to rotate a empty stack\n", top);
	if(*stack == (*stack)->next)
		my_error("Try to rotate a Stack with only one structure\n", top);
	*stack = (*stack)->next;
	return(*stack);
}

t_stack	*reverse_rotate(t_stack **stack, t_both *top)
{
	if(*stack == NULL)
		my_error("Try to reverse rotate a empty stack\n", top);
	if(*stack == (*stack)->next)
		my_error("Try to reverse rotate a Stack with only one structure\n", top);
	*stack = (*stack)->back;
	return(*stack);
}

int	r_or_rr(t_stack *stack, t_stack *target, t_both *top)
{
	int r;
	int rr;
	t_stack *tmp;

	if (target == NULL)
		my_error("r_or_rr got NULL for insert", top);
	if (stack == NULL)
		return(0);
	r = 0;
	rr = 0;
	tmp = stack;
	while(tmp != target)
	{
		r++;
		tmp = tmp->next;
	}
	tmp = stack;
	while(tmp != target)
	{
		rr++;
		tmp = tmp->back;
	}
	if(r <= rr)
		return(r);
	else
		return(rr * -1);
}

void	rotate_to_top_a(t_both *top, t_stack *target)
{
	int	i;

	if (top->stack_a == NULL)
		return;
	i =  r_or_rr(top->stack_a, target, top);
	if (i < 0)
	{
		while( i < 0)
		{
			rules(RRA,top);
			i++;
		}
	}
	else
	{
		while( i > 0)
		{
			rules(RA,top);
			i--;
		}
	}
}

void	rotate_to_top_b(t_both *top, t_stack *target)
{
	int	i;

	if (top->stack_b == NULL)
		return;
	i =  r_or_rr(top->stack_b, target, top);
	if (i < 0)
	{
		while( i < 0)
		{
			rules(RRB, top);
			i++;
		}
	}
	else
	{
		while( i > 0)
		{
			rules(RB, top);
			i--;
		}
	}
}