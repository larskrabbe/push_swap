/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:01:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 16:55:03 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

# define B_valid B != NULL && B->next != B
# define A_valid A != NULL && A->next != A

t_stack *where_to_insert(t_stack *stack, t_stack *insert)
{
	t_stack	*tmp;

	if (insert == NULL)
		my_error("where_to_insert got NULL for insert");
	if (stack == NULL)
		return(NULL);
	tmp = is_smallest(stack);
	if (insert->index < tmp->index)
		return(tmp);
	tmp = is_biggest(stack);
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
		my_error("where_to_insert didnt find a place");
	return(NULL);
}

t_stack *where_to_insert_reverse(t_stack *stack, t_stack *insert)
{
	t_stack	*tmp;

	if (insert == NULL)
		my_error("where_to_insert got NULL for insert");
	if (stack == NULL)
		return(NULL);
	tmp = is_smallest(stack);
	if (insert->index < tmp->index)
		return(tmp->next);
	tmp = is_biggest(stack);
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
		my_error("where_to_insert didnt find a place");
	return(NULL);
}

void	sort_stack(t_main *m_s)
{
	if(stack_length(A) <= 5)
		quick_sort(m_s);
	else
		chunk_sort(m_s);
		
}
