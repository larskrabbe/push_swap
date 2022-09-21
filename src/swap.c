/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:56:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/21 18:12:08 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack *swap(t_stack *stack)
{
	t_stack *tmp;

	if(stack == NULL || stack->next == stack)
		return(stack);
	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	tmp->back = stack->back;
	stack->back = tmp;
	return(tmp);
}

void	swap_both(t_main *m_s)
{
	swap(m_s->stack_a);
	swap(m_s->stack_b);
}
