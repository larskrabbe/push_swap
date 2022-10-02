/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:23:04 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 15:26:48 by lkrabbe          ###   ########.fr       */
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

int	r_or_rr(t_stack *stack,t_stack *target)
{
	int r;
	int rr;
	t_stack *tmp;

	if (target == NULL)
		my_error("r_or_rr got NULL for insert");
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

void	rotate_to_top_a(t_main *m_s,t_stack *target)
{
	int	i;

	if (m_s->stack_a == NULL)
		return;
	i =  r_or_rr(m_s->stack_a,target);
	if (i < 0)
	{
		while( i < 0)
		{
			rules(RRA,m_s);
			i++;
		}
	}
	else
	{
		while( i > 0)
		{
			rules(RA,m_s);
			i--;
		}
	}
}

void	rotate_to_top_b(t_main *m_s,t_stack *target)
{
	int	i;

	if (m_s->stack_b == NULL)
		return;
	i =  r_or_rr(m_s->stack_b,target);
	if (i < 0)
	{
		while( i < 0)
		{
			rules(RRB,m_s);
			i++;
		}
	}
	else
	{
		while( i > 0)
		{
			rules(RB,m_s);
			i--;
		}
	}
}