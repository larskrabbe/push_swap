/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:12:20 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/21 19:02:40 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"


/*
	pulls a top structer from a stack and fixed the pointer in it

	returns the structure
*/
 t_stack *pull(t_stack *stack)
{
	t_stack *tmp;

	if (stack == NULL)
		return(NULL);
	tmp = stack;
	if (stack == stack->next)
	{
		stack = NULL;
	}
	else
	{
		tmp->next->back = tmp->back;
		stack = stack->next;
		tmp->back->next = tmp->next;
	}
	tmp->back = NULL;
	tmp->next = NULL;
	return(stack);
}


void	push_a(t_stack *stack_a,t_stack *stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	if (stack_b == NULL)//cant push nothing, will maybe returns a error int
		return;

	stack_b->back = stack_a->back;
}