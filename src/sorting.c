/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:01:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/12 11:19:43 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

# define B_valid B != NULL && B->next != B
# define A_valid A != NULL && A->next != A

t_stack *where_to_insert(t_stack *stack, t_stack *insert, t_both *top)
{
	t_stack	*tmp;

	if (insert == NULL)
		my_error("where_to_insert got NULL for insert", top);
	if (stack == NULL)
		return(NULL);
	tmp = is_smallest(stack, top);
	if (insert->index < tmp->index)
		return(tmp);
	tmp = is_biggest(stack, top);
	if (insert->index > tmp->index)
		return(tmp->next);
	tmp = stack;
	while(tmp->next != stack)
	{
		if (insert->index < tmp->index && insert->index > tmp->back->index)
				return(tmp);
		tmp = tmp->next;
	}
	if (insert->index < tmp->index && insert->index > tmp->back->index)
			return(tmp);
	if(!(insert->index < tmp->index && insert->index > tmp->back->index))
		my_error("where_to_insert didnt find a place", top);
	return(NULL);
}

t_stack *where_to_insert_reverse(t_stack *stack, t_stack *insert, t_both *top)
{
	t_stack	*tmp;

	if (insert == NULL)
		my_error("where_to_insert got NULL for insert", top);
	if (stack == NULL)
		return(NULL);
	tmp = is_smallest(stack, top);
	if (insert->index < tmp->index)
		return(tmp->next);
	tmp = is_biggest(stack, top);
	if (insert->index > tmp->index)
		return(tmp);
	tmp = stack;
	while(tmp->next != stack)
	{
		if (insert->index > tmp->index && insert->index < tmp->back->index)
				return(tmp);
		tmp = tmp->next;
	}
	if (insert->index > tmp->index && insert->index < tmp->back->index)
			return(tmp);
	if(!(insert->index < tmp->index && insert->index > tmp->back->index))
		my_error("where_to_insert didnt find a place", top);
	return(NULL);
}


static int	is_sorted(t_both *top)
{
	t_stack *tmp;

	tmp = top->stack_a;
	while (tmp->next != top->stack_a)
	{
		if (tmp->index < tmp->next->index)
			tmp = tmp->next;
		else
			return (0);
	}
	if (tmp->index > top->stack_a->index)
		return (1);
	else
		return (0);
}

void	sort_stack(t_both *top)
{
	if(stack_length(A) == 1)
		return;
	if(is_sorted(top))
		return;
	//print_stack_index(top->stack_a);
	if(stack_length(A) <= 5)
		quick_sort(top);
	else
		chunk_sort(top);
}
