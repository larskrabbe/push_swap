/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:56:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/23 16:35:12 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack *swap(t_stack *stack)
{
	t_stack *tmp;

	if (stack == NULL)
		my_error("trying to swap a stack with ZERO structs");
	if (stack->next == stack)
		my_error("trying to swap a stack with one struct");
	tmp = stack->next;
	tmp->next->back = stack;
	stack->next = tmp->next;
	tmp->next = stack;
	tmp->back = stack->back;
	stack->back->next = tmp;
	stack->back = tmp;
	return(tmp);
}

void	swap_both(t_main *m_s)
{
	m_s->stack_a = swap(m_s->stack_a);
	m_s->stack_b = swap(m_s->stack_b);
}

