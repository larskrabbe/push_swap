/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/11 14:09:49 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	create a new list member at the end of the list and set the value to the desired input

	t_stack stack -> if already existing it the new member will be added at the end if not it will be created
	int	value -> value that will be inserted
	
	return -> returns the top position of the stack
*/
static void	add_stack(t_both *top, int value)
{
	t_stack *tmp;
	
	if(top->stack_a != NULL && look_for_value(top->stack_a, value) != NULL)
				my_error("value already exist", top);
	tmp = ft_calloc(1,sizeof(t_stack));
	if (tmp == NULL)
		my_error("allocation failed in f create_new_stack", top);
	if (top->stack_a == NULL)
		top->stack_a = tmp;
	else
	{	
		tmp->back = top->stack_a->back;
		top->stack_a->back->next = tmp;
	}
	top->stack_a->back = tmp;
	tmp->next = top->stack_a;
	tmp->value = value;
	tmp->index = 0;
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
			return (0);
		if (i >= 8)
			if(ft_atoi(str) == 0 || ft_atoi(str) == -1)
				return (0);
		i++;
	}
	if (ft_isdigit(str[i - 1]) == 1)
		return(1);
	else
		return(0);
}

/*
	increment the current index if there not under the smallest value that reach his max

	t_stack *stack -> current stack
	int *next_smallest -> the possible next smallest value , if something smaller is found this will be updated 
	int *smallest -> the current smallest value , everything over will ++ the index
	
	return -> returns the next stack in line
*/
static t_stack	*index_pp(t_stack *stack,int *next_smallest,int *smallest)
{
	if (stack->value < *next_smallest && stack->value > *smallest)
	{
		*next_smallest = stack->value;// to get next smallest
	}
	if (stack->value > *smallest)
	{
		stack->index++;
	}
	return(stack->next);
}

/*
	add a index depeding on the value of the stack,
	starting from 0 the index will increase if the value is increase from the last smaller one,
	not depending on the diffrent of the increase

	t_stack *stack -> the stack
	int stacksize -> current size of the stack

	return -> returns the top position of the stack
*/
static t_stack	*add_index(t_stack *stack,int stacksize , t_both *top)
{
	int smallest;
	int next_smallest;
	t_stack *tmp;
	
	if (stack == NULL)
		return(NULL);
	tmp = stack;
	smallest = is_smallest(stack, top)->value;
	while (stacksize >= 0)
	{
		next_smallest = is_biggest(stack, top)->value;
		while(tmp->next != stack)
			tmp = index_pp(tmp,&next_smallest,&smallest);;
		tmp = index_pp(tmp, &next_smallest, &smallest);;
		smallest = next_smallest;
		stacksize--;
	}
	return(stack);
}

t_stack	*stack_setup(int argv,char *argc[],t_both *top)
{
	int		i;
	char	**strings;
	int		p;

	top->max = 0;
	p = 1;
	while(p < argv)
	{
		i = 0;
		strings = ft_split(argc[p], ' ');
		if(strings == NULL && strings[0] == NULL)
			my_error("ft_split failed", top);
		while (strings[i] != NULL)
		{
			if (check_for_valid_number(strings[i]) != 1)
				my_error("contains not allowed input", top);
			add_stack(top, ft_atoi(strings[i]));
			top->max++;
			free(strings[i]);
			i++;
		}
		free(strings);
		p++;
	}
	return(add_index(top->stack_a, top->max, top));
}
