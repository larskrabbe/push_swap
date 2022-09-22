/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:43:19 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/22 20:37:09 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

# define BACK m_s->stack_a->back
# define NEXT m_s->stack_a->next
# define CRNT m_s->stack_a


int is_small_big(t_stack *stack_a)
{
	t_stack *tmp;
	short end;

	end =0;
	tmp = stack_a;
	while(tmp->next != stack_a)
	{
		// printf("tmp->value = %i == tmp->next->value = %i end = %i\n",tmp->value , tmp->next->value, end);
		// fflush(stdout);
		if(tmp->value > tmp->next->value)
		{
			if(end == 0)
				end = 1;
			else
				return(-1);
		}	
		tmp = tmp->next;
	}
	if (tmp->value > tmp->next->value)
	{
			if(end == 0)
				return(1);
			else
				return(-1);
	}
	return(1);
}
// 1 54 311 65 2 8 66 18 123 654 21 654 321 53 3 52 21 51
void	sort_stack(t_main *m_s)
{
	while(is_small_big(m_s->stack_a) == -1)
	{
		if(CRNT->value > NEXT->value)
			if (CRNT->value < NEXT->next->value)
				rules(SA,m_s);
			else
				rules(PB,m_s);
		else
			rules(RA,m_s);
		if(m_s->stack_b != NULL)
		{
		if (m_s->stack_b->value > BACK->value && m_s->stack_b->value < CRNT->value)
			rules(PA,m_s);
		}
	}
}