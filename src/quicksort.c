/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:28:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 15:28:39 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	quick_sort(t_main *m_s)
{
	while(stack_length(A) > 3)
		rules(PB,m_s);
	if (is_smallest(A)->next == is_biggest(A))
		rules(SA,m_s);
	if (A != is_smallest(A))
	{
		if(A == is_biggest(A))
			rules(RA,m_s);
		else
			rules(RRA,m_s);
	}
	while(B != NULL)
	{
		if(r_or_rr(A,where_to_insert(A,B)) == 0)
			rules(PA,m_s);
		else if(r_or_rr(A,where_to_insert(A,B)) < 0)
			rules(RRA,m_s);
		else
			rules(RA,m_s);
	}
	rotate_to_top_a(m_s,is_smallest(m_s->stack_a));
}

