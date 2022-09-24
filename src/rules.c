/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:25:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/24 20:42:55 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	rule Funktion for rotating, because the the rules funktion is to BIG for norminette
*/
static void	rotate_rules(char *rule,t_main *m_s)
{
	if (rule[2] == '\0')
	{
			if (rule[1] == 'a' || rule[1] == 'r')
				m_s->stack_a = rotate(&m_s->stack_a);
			if (rule[1] == 'b' || rule[1] == 'r')
				m_s->stack_b = rotate(&m_s->stack_b);
	}
	else
	{
			if (rule[2] == 'a' || rule[2] == 'r')
				m_s->stack_a = reverse_rotate(&m_s->stack_a);
			if (rule[2] == 'b' || rule[2] == 'r')
				m_s->stack_b = reverse_rotate(&m_s->stack_b);
	}	
}

void	rules(char *rule,t_main *m_s)
{
	if (rule[0] == 's')
	{
		if (rule[1] == 'a' || rule[1] == 's')
			m_s->stack_a = swap(m_s->stack_a);
		if (rule[1] == 'b' || rule[1] == 's')
			m_s->stack_b = swap(m_s->stack_b);
	}
	else if (rule[0] == 'p')
	{
		if (rule[1] == 'a')
			push(&m_s->stack_a,&m_s->stack_b);
		else
			push(&m_s->stack_b,&m_s->stack_a);
	}
	else
		rotate_rules(rule,m_s);
	if (rule[2] == '\0')
		write(1,rule,2);
	else
		write(1,rule,3);
	write(1,"\n",1);
	// print_stack((m_s->stack_a));
	// print_stack((m_s->stack_b));
	// write(1,"\n",1);
}