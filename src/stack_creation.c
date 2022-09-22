/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/22 19:36:14 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	create a new list member at the end of the list and set the value to the desired input

	t_stack stack -> if already existing it the new member will be added at the end if not it will be created
	int	value -> value that will be inserted
*/
static t_stack	*add_stack(t_stack *stack, int value, int count)
{
	t_stack *tmp;
	t_stack	*top;
	
	top = stack; 
	tmp = calloc(1,sizeof(t_stack));
	if (tmp == NULL)
	{
		ft_putstr_fd("allocation failed in f create_new_stack",1);
		return(NULL);
	}
	if (top == NULL)
	{
		top = tmp;
		top->next = top;
		top->back = top;
	}
	else
	{	
		tmp->back = top->back;
		tmp->next = top;
		top->back->next = tmp;
		top->back = tmp;
	}
	tmp->value = value;
	tmp->num = count;
	
	return(top);
}

t_stack	*stack_setup(int argv,char *argc[],t_stack *stack)
{
	int		i;

	i = 1;
	while(argv > i)
	{
		stack = add_stack(stack,ft_atoi(argc[i]),i);//need to check if the inout is valid
		i++;
	}
	return(stack);
}
