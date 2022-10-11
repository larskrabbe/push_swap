/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:25:09 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/10 22:35:31 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack	*next_chunk(t_stack *stack,int chunk,int chunksize)
{
	t_stack	*tmp_next;
	t_stack *tmp_back;

	tmp_next = stack;
	tmp_back = stack;
	while(tmp_next->next != stack)
	{
		if (tmp_next->index < (chunk * chunksize))
			return(tmp_next);
		if(tmp_back->index < (chunk * chunksize))
			return(tmp_back);
		tmp_next = tmp_next->next;
		tmp_back = tmp_back->back;
	}
	if (tmp_next->index < chunk * chunksize)
		return(tmp_next);
	else if(tmp_back->index < chunk * chunksize)
		return(tmp_back);
	else
		return(NULL);
}


void	chunk_push(t_both *top,int chunksize)
{
	int		chunk;
	t_stack	*tmp;

	chunk = 1;
	while (B != NULL)
	{
		tmp = next_chunk(top->stack_b,chunk,chunksize);
		if (tmp == NULL)
			{
				chunk++;
				tmp = next_chunk(top->stack_b,chunk,chunksize);
			};
		rotate_to_top_b(top,tmp);
		tmp = where_to_insert(top->stack_a, tmp, top);
		if(A != NULL)
			rotate_to_top_a(top,tmp);
		rules(PA,top);
	}
}

void	chunking(t_both *top)
{
	int chunksize;
	t_stack *tmp;

	tmp = NULL;
	chunksize = is_biggest(top->stack_a, top)->index / 3;
	while(top->stack_a)
	{
		if(top->stack_a->index >= chunksize * 2)
			rules(PB,top);
		else if(top->stack_a->index >= chunksize)
		{
			rules(PB,top);
			if(top->stack_b !=  top->stack_b->next && top->stack_b != NULL)
				rules(RB,top);
		}
		else if(top->stack_a == tmp )
			break;
		else
		{
			if (tmp == NULL)
				tmp = top->stack_a;
			if(top->stack_a !=  top->stack_a->next)
				rules(RA,top);
		}
	}
}

void	chunk_sort(t_both *top)
{
	chunking(top);
	chunking(top);
	while (top->stack_a != NULL)
		rules(PB,top);
	chunk_push(top,top->max/15);
	rotate_to_top_a(top,is_smallest(top->stack_a, top));
}