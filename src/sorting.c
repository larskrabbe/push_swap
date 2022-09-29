/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:01:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/29 15:13:15 by lkrabbe          ###   ########.fr       */
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
	printf("target before %i",tmp->index);
	while(tmp->next != stack)
	{
		printf("\nin loop \n top %i\nback %i\n",tmp->index,tmp->back->index);
		if (insert->index < tmp->index && insert->index > tmp->back->index)
			return(tmp);
		tmp = tmp->next;
	}
	if (insert->index < tmp->index && insert->index > tmp->back->index)
		return(tmp);
	tmp = tmp->next;
	if(!(insert->index > tmp->index && insert->index < tmp->back->index))
		my_error("where_to_insert didnt find a place");
	return(tmp);
}


/**
 * @brief 
 * !needs to be sorted to work
 */
int	r_or_rr(t_stack *stack,t_stack *target)
{
	int r;
	int rr;
	t_stack *tmp;

	if (target == NULL)
		my_error("r_or_rr got NULL for insert");
	if (stack == NULL)
		return(0);
	r = 0;
	rr = 0;
	tmp = stack;
	while(tmp != target)
	{
		r++;
		tmp = tmp->next;
	}
	tmp = stack;
	while(tmp != target)
	{
		rr++;
		tmp = tmp->back;
	}
	if(r <= rr)
		return(r);
	else
		return(rr * -1);
}

void	rotate_to_top(t_main *m_s)
{
	int	i;

	i =  r_or_rr(m_s->stack_a,is_smallest(m_s->stack_a));
	if (i < 0)
	{
		while( i < 0)
		{
			rules(RRA,m_s);
			i++;
		}
	}
	else
	{
		while( i > 0)
		{
			rules(RA,m_s);
			i--;
		}
	}
}	

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
		printf("r_or_rr = %i \n",r_or_rr(A,where_to_insert(A,B)));
		if(r_or_rr(A,where_to_insert(A,B)) == 0)
			rules(PA,m_s);
		else if(r_or_rr(A,where_to_insert(A,B)) < 0)
			rules(RA,m_s);
		else
			rules(RRA,m_s);
	}
	rotate_to_top(m_s);
}

void	sort_stack(t_main *m_s)
{
	if(stack_length(A) <= 5)
	quick_sort(m_s);
}
