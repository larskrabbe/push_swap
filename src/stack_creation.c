/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/24 21:05:02 by lkrabbe          ###   ########.fr       */
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
	t_stack *tmp;
	t_stack	*top;
	tmp = ft_calloc(1,sizeof(t_stack));
	if (tmp == NULL)
	{
		ft_putstr_fd("allocation failed in f create_new_stack",1);
		return(NULL);
	}
	top = stack; 
	if (stack == NULL)
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
	
	return(top);
}

/*
	checks if the string would be a valid number
	cant contain multiple + or - signs and any other chars

	char *str -> string that will be check if it a number
	returns -> 1 if it valid and 0 if not
*/
static int	check_for_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			return(0);
		i++;
	}
	if (ft_isdigit(str[i - 1]) == 1)
		return(1);
	else
		return(0);
}

t_stack *add_index(t_stack *stack,int stacksize)
{
	int next_biggest;
	int i;
	t_stack *tmp;
	next_biggest = is_biggest(stack);
	
	i = is_smallest(stack);
	while(stack->next == stack)
	{
		if (stack->value > i && stack->value < next_biggest)
			tmp = stack;
		stack = stack->next;
	}
		if (stack->value > i && stack->value < next_biggest)
			tmp = stack;
}


t_stack	*stack_setup(int argv,char *argc[],t_stack *stack)
{
	int			i;
	char	**strings;
	int			p = argv;
	int			stacksize;

	stacksize = 0;
	p = 1;
	while(p < argv)
	{
		i = 0;
		strings = ft_split(argc[p], ' ');
		if(strings[0] == NULL)
			my_error("contains not allowed input");// need to free evrything
		while (strings[i] != NULL)
		{
			if(check_for_valid_number(strings[i]) != 1)
				my_error("contains not allowed input");
			stack = add_stack(stack,ft_atoi(strings[i]));//need to check if the inout is valid
			stacksize++;
			free(strings[i]);
			i++;
		}
		free(strings);
		p++;
	}
	add_index(stack,stacksize);
	return(stack);
}
