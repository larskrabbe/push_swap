/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:19:55 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 01:16:19 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	while(stack != NULL)
	{
		free(pull(&stack));
	}
}

void	free_two_stacks(t_main *m_s)
{
	free_stack(m_s->stack_a);
	free_stack(m_s->stack_b);
}