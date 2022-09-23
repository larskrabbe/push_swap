/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:43:19 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/23 09:52:08 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

# define BACK m_s->stack_a->back
# define NEXT m_s->stack_a->next
# define CRNT m_s->stack_a

int is_smallest(t_stack *stack)
{
	t_stack *tmp;
	int 	smallest;
	
	if (stack == NULL)
		my_error("EMPTY STACK in smallest function");
	smallest = stack->value;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value < smallest)
		smallest = tmp->value;
	return(smallest);
}

int is_biggest(t_stack *stack)
{
	t_stack *tmp;
	int 	biggest;
	
	if (stack == NULL)
		my_error("EMPTY STACK in biggest function");
	biggest = stack->value;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > biggest)
		biggest = tmp->value;
	return(biggest);
}

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

void	sort_stack(t_main *m_s)
{
	while(is_small_big(m_s->stack_a) == -1)
	{
		if(CRNT->value > NEXT->value && CRNT->value != is_biggest(m_s->stack_a))
			if (CRNT->value < NEXT->next->value || NEXT->next->value  == is_smallest(CRNT))
				rules(SA,m_s);
			else
				rules(PB,m_s);
		else
			rules(RA,m_s);
		if(m_s->stack_b != NULL)
		{
			if (m_s->stack_b->value > BACK->value && m_s->stack_b->value < CRNT->value)
				rules(PA,m_s);
			if (m_s->stack_b != NULL && m_s->stack_b->value < is_smallest(m_s->stack_a) && is_smallest(m_s->stack_a) == CRNT->value)
				rules(PA,m_s);
			if (m_s->stack_b != NULL && m_s->stack_b->value > is_biggest(m_s->stack_a) && is_biggest(m_s->stack_a) == BACK->value)
				rules(PA,m_s);
		}
		//print_stack(m_s->stack_a);
	}
	while(m_s->stack_b != NULL)
	{
		if (m_s->stack_b->value > BACK->value && m_s->stack_b->value < CRNT->value)
			rules(PA,m_s);
		else if (m_s->stack_b != NULL && m_s->stack_b->value < is_smallest(m_s->stack_a) && is_smallest(m_s->stack_a) == CRNT->value)
			rules(PA,m_s);
		else if (m_s->stack_b != NULL && m_s->stack_b->value > is_biggest(m_s->stack_a) && is_biggest(m_s->stack_a) == BACK->value)
			rules(PA,m_s);
		else
			rules(RA,m_s);

	}
	while(CRNT->value != is_smallest(CRNT))
		rules(RA,m_s);
}		
