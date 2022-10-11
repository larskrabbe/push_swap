/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:25:26 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/10 08:55:35 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	rule Funktion for rotating, because the the rules funktion is to BIG for norminette
*/
inline static void	rotate_rules(char *rule, t_both *top)
{
	if (rule[2] == '\0')
	{
			if (rule[1] == 'a' || rule[1] == 'r')
				top->stack_a = rotate(&top->stack_a, top);
			if (rule[1] == 'b' || rule[1] == 'r')
				top->stack_b = rotate(&top->stack_b, top);
	}
	else
	{
			if (rule[2] == 'a' || rule[2] == 'r')
				top->stack_a = reverse_rotate(&top->stack_a, top);
			if (rule[2] == 'b' || rule[2] == 'r')
				top->stack_b = reverse_rotate(&top->stack_b, top);
	}	
}

void	rules(char *rule, t_both *top)
{
	if (rule[0] == 's')
	{
		if (rule[1] == 'a' || rule[1] == 's')
			top->stack_a = swap(top->stack_a, top);
		if (rule[1] == 'b' || rule[1] == 's')
			top->stack_b = swap(top->stack_b, top);
	}
	else if (rule[0] == 'p')
	{
		if (rule[1] == 'a')
			push(&top->stack_a, &top->stack_b, top);
		else
			push(&top->stack_b, &top->stack_a, top);
	}
	else
		rotate_rules(rule, top);
	if (rule[2] == '\0')
		write(1, rule, 2);
	else
		write(1,rule,3);
	write(1,"\n",1);
}