/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:25:09 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 16:16:55 by lkrabbe          ###   ########.fr       */
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


void	chunk_push(t_main *m_s,int chunksize)
{
	int		chunk;
	t_stack	*tmp;

	chunk = 1;
	while (A != NULL)
	{
		tmp = next_chunk(m_s->stack_a,chunk,chunksize);
		if (tmp == NULL)
			{
				chunk++;
				tmp = next_chunk(m_s->stack_a,chunk,chunksize);
			};
		rotate_to_top_a(m_s,tmp);
		tmp = where_to_insert_reverse(m_s->stack_b,tmp);
		if(B != NULL)
			rotate_to_top_b(m_s,tmp);
		rules(PB,m_s);
	}
	
}

void	chunk_sort(t_main *m_s)
{
	int chunksize;// need to figure out chunksize later

	chunksize  = 20;
	while(A != NULL)
	{
		chunk_push(m_s,chunksize);
	}
	while(B != NULL)
		rules(PA,m_s);
	rotate_to_top_a(m_s,is_smallest(m_s->stack_a));
}