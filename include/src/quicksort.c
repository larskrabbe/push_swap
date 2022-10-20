/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:28:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/13 16:04:46 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	quick_sort(t_both *top)
{
	t_stack	*tmp;

	while (stack_length(top->stack_a) > 3)
		rules(PB, top);
	if (is_smallest(top->stack_a, top)->next == is_biggest(top->stack_a, top))
		rules(SA, top);
	if (top->stack_a != is_smallest(top->stack_a, top))
	{
		if (top->stack_a == is_biggest(top->stack_a, top))
			rules(RA, top);
		else
			rules(RRA, top);
	}
	while (top->stack_b != NULL)
	{
		tmp = where_to_insert(top->stack_a, top->stack_b, top);
		if (r_or_rr(top->stack_a, tmp) == 0)
			rules(PA, top);
		else if (r_or_rr(top->stack_a, tmp) < 0)
			rules(RRA, top);
		else
			rules(RA, top);
	}
	rotate_to_top_a(top, is_smallest(top->stack_a, top));
}
