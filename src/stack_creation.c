/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/13 16:02:53 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	create a new list member at the end of the list and set the 
	value to the desired input

	t_stack stack -> if already existing it the new member will be added
	 at the end if not it will be created
	int	value -> value that will be inserted
	
	return -> returns the top position of the stack
*/
static void	add_stack(t_both *top, int value)
{
	t_stack	*tmp;

	if (top->stack_a != NULL && look_for_value(top->stack_a, value) != NULL)
		my_error("value already exist", top);
	tmp = ft_calloc(1, sizeof(t_stack));
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
	increment the current index if there not under the smallest 
	value that reach his max

	t_stack *stack -> current stack
	int *next_smallest -> the possible next smallest value ,
	 if something smaller is found this will be updated 
	int *smallest -> the current smallest value , everything over will ++ the index
	
	return -> returns the next stack in line
*/
static t_stack	*index_pp(t_stack *stack, int *next_smallest, int *smallest)
{
	if (stack->value < *next_smallest && stack->value > *smallest)
	{
		*next_smallest = stack->value;
	}
	if (stack->value > *smallest)
	{
		stack->index++;
	}
	return (stack->next);
}

/**
*	add a index depeding on the value of the stack,
*	starting from 0 the index will increase if the 
* 	value is increase from the last smaller one,
*	not depending on the diffrent of the increase
*
*	@param stack -> the stack
*	@param stacksize --> current size of the stack
*
*	@return returns the top position of the stack
*/
t_stack	*add_index(t_stack *stack, int stacksize, t_both *top)
{
	int		smallest;
	int		next_smallest;
	t_stack	*tmp;

	if (stack == NULL)
		return (NULL);
	tmp = stack;
	smallest = is_smallest(stack, top)->value;
	while (stacksize >= 0)
	{
		next_smallest = is_biggest(stack, top)->value;
		while (tmp->next != stack)
			tmp = index_pp(tmp, &next_smallest, &smallest);
		tmp = index_pp(tmp, &next_smallest, &smallest);
		smallest = next_smallest;
		stacksize--;
	}
	return (stack);
}

void	check_input(char *str, t_both *top)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' )
			i++;
		else if ((str[i] == '-' || str[i] == '+' )
			&& str[i - 1] == ' ' && ft_isdigit(str[i + 1]))
			i++;
		else if ((str[i] == '-' || str[i] == '+' )
			&& i == 0 && ft_isdigit(str[i + 1]))
			i++;
		else
			my_error("not allowed character inside", top);
	}
}

void	strings_to_struct(char **str, t_both *top, long long int num)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		num = my_atoli(str[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_strings(str);
			my_error("number is outside range ", top);
		}
		add_stack(top, num);
		top->max++;
		if (str[i] != NULL)
			free(str[i]);
		i++;
	}
}
