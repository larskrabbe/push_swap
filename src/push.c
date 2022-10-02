/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:12:20 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 01:15:07 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	pulls a top structer from a stack and fixed the pointer in it

	returns the structure with next and back equel to NULL
*/
t_stack	*pull(t_stack **stack)
{
	t_stack *tmp;

	if (*stack == NULL)
	{
		my_error("trying to pull from empty stack");
	}
	tmp = *stack;
	if (*stack == (*stack)->next)
	{
		*stack = NULL;
	}
	else
	{
		tmp->next->back = tmp->back;
		*stack = (*stack)->next;
		tmp->back->next = tmp->next;
	}
	tmp->back = NULL;
	tmp->next = NULL;
	return(tmp);
}

static t_stack	*insert(t_stack *stack, t_stack *new)
{
	if (new == NULL)
	{
		my_error("try to insert NULL");
	}
	if (stack == NULL)
	{
		new->back = new;
		new->next = new;
		stack = new;
	}
	else
	{
		new->next = stack;
		new->back = stack->back;
		stack->back->next = new; 
		stack->back = new;
		stack = new;
	}
	return(stack);
}

void	push(t_stack **stack_insert,t_stack **stack_pull)
{
	t_stack *tmp;

	tmp = pull(stack_pull);
	*stack_insert = insert(*stack_insert,tmp);
}