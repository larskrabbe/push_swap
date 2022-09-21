/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/21 17:51:52 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	create a new list member at the end of the list and set the value to the desired input

	t_stack stack -> if already existing it the new member will be added at the end if not it will be created
	int	value -> value that will be inserted
*/
static t_stack	*add_stack(t_stack *stack, int value)
{
	t_stack *tmp = NULL;
	t_stack	*last = NULL;

	tmp = calloc(1,sizeof(t_stack));
	if (tmp == NULL)
	{
		ft_putstr_fd("allocation failed in f create_new_stack",1);
		return(NULL);
	}
	if (stack == NULL)
	{
		stack = tmp;
		stack->next = stack;
		stack->back = stack;
	}
	else
	{
		last = stack->back;
		tmp->back = last;
		tmp->next = stack;
		stack->back->next = tmp;
		stack->back = tmp;
	}
	tmp->value = value;
	return(stack);
}

t_stack	*stack_setup(int argv,char *argc[],t_stack *stack)
{
	int		i;

	i = 1;
	while(argv > i)
	{
		stack = add_stack(stack,ft_atoi(argc[i]));//need to check if the inout is valid
		i++;
	}
	return(stack);
}
