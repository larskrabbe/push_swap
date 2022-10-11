/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:56:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/10 08:38:51 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack *swap(t_stack *stack, t_both *top)
{
	t_stack *tmp;

	if (stack == NULL)
		my_error("trying to swap a stack with ZERO structs", top);
	if (stack->next == stack)
		my_error("trying to swap a stack with one struct", top);
	tmp = stack->next;
	tmp->next->back = stack;
	stack->next = tmp->next;
	tmp->next = stack;
	tmp->back = stack->back;
	stack->back->next = tmp;
	stack->back = tmp;
	return(tmp);
}

void	swap_both(t_both *top)
{
	top->stack_a = swap(top->stack_a, top);
	top->stack_b = swap(top->stack_b, top);
}

