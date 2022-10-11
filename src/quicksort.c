/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:28:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/11 08:59:07 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	quick_sort(t_both *top)
{
	while(stack_length(A) > 3)
		rules(PB, top);
	if (is_smallest(A, top)->next == is_biggest(A, top))
		rules(SA, top);
	if (A != is_smallest(A, top))
	{
		if(A == is_biggest(A, top))
			rules(RA, top);
		else
			rules(RRA, top);
	}
	while(B != NULL)
	{
		if (r_or_rr(A, where_to_insert(A, B, top), top) == 0)
			rules(PA, top);
		else if(r_or_rr(A, where_to_insert(A, B, top), top) < 0)
			rules(RRA, top);
		else
			rules(RA, top);
	}
	rotate_to_top_a(top, is_smallest(top->stack_a, top));
}

