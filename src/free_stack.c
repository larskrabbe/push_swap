/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:19:55 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/20 17:32:59 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	free_stack(t_stack *stack, t_both *top)
{
	while (stack != NULL)
	{
		free(pull(&stack, top));
	}
}

void	free_two_stacks(t_both *top)
{
	free_stack(top->stack_a, top);
	free_stack(top->stack_b, top);
}
