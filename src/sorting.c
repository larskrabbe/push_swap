/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:01:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 16:12:10 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

# define BACK m_s->stack_a->back
# define NEXT m_s->stack_a->next
# define CRNT m_s->stack_a

// 1 54 311 65 2 8 66 18 123 654 21 654 321 53 3 52 21 51
//just a idee 
// typedef struct t_rule{
	
// 	int rule;	
	

// 	struct t_rule *next[4];//combination from RA RR or RRA RRR until the next one found
// }s_rule;
// void	what_rotation
// {	
// 	while(is_small_big(m_s->stack_a) == -1)
// 	{
// 		while(next_opration(t_main *ra_fake) != RA)
// 			next_opration(t_main *m_s) != RA
// 	}
// }


/*
	version 1
*/
// void	sort_stack(t_main *m_s)
// {
// 	while(is_small_big(m_s->stack_a) == -1)
// 	{
// 		if(CRNT->value > NEXT->value && CRNT->value != is_biggest(m_s->stack_a))
// 			if (CRNT->value < NEXT->next->value || NEXT->next->value  == is_smallest(CRNT))
// 				rules(SA,m_s);
// 			else
// 				rules(PB,m_s);
// 		else
// 		if(CRNT->value == is_biggest(m_s->stack_a) && NEXT->value > BACK->value)
// 			rules(SA,m_s);
// 		else
// 			rules(RA,m_s);
// 		while(m_s->stack_b != NULL)
// 		{
// 			if (m_s->stack_b->value > BACK->value && m_s->stack_b->value < CRNT->value)
// 				rules(PA,m_s);
// 			else if (m_s->stack_b != NULL && m_s->stack_b->value < is_smallest(m_s->stack_a) && is_smallest(m_s->stack_a) == CRNT->value)
// 				rules(PA,m_s);
// 			else if (m_s->stack_b != NULL && m_s->stack_b->value > is_biggest(m_s->stack_a) && is_biggest(m_s->stack_a) == BACK->value)
// 				rules(PA,m_s);
// 			else
// 				break;
// 		}
// 		//print_stack(m_s->stack_a);
// 	}
// 	while(m_s->stack_b != NULL)
// 	{
// 		if (m_s->stack_b->value > BACK->value && m_s->stack_b->value < CRNT->value)
// 			rules(PA,m_s);
// 		else if (m_s->stack_b != NULL && m_s->stack_b->value < is_smallest(m_s->stack_a) && is_smallest(m_s->stack_a) == CRNT->value)
// 			rules(PA,m_s);
// 		else if (m_s->stack_b != NULL && m_s->stack_b->value > is_biggest(m_s->stack_a) && is_biggest(m_s->stack_a) == BACK->value)
// 			rules(PA,m_s);
// 		else
// 			rules(RA,m_s);

// 	}
// 	while(CRNT->value != is_smallest(CRNT))
// 		rules(RA,m_s);


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
