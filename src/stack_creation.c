/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/25 14:03:59 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

/*
	create a new list member at the end of the list and set the value to the desired input

	t_stack stack -> if already existing it the new member will be added at the end if not it will be created
	int	value -> value that will be inserted
	
	return -> returns the top position of the stack
*/
static t_stack	*add_stack(t_stack *stack, int value)
{
	t_stack *tmp;

	if(stack != NULL && look_for_value(stack, value) != NULL)
				my_error("value already exist");
	tmp = ft_calloc(1,sizeof(t_stack));
	if (tmp == NULL)
		my_error("allocation failed in f create_new_stack");
	if (stack == NULL)
		stack = tmp;
	else
	{	
		tmp->back = stack->back;
		stack->back->next = tmp;
	}
	stack->back = tmp;
	tmp->next = stack;
	tmp->value = value;
	tmp->index = 0;
	return(stack);
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
static t_stack	*add_index(t_stack *stack,int stacksize)
{
	int smallest;
	int next_smallest;
	t_stack *tmp;
	
	tmp = stack;
	smallest = is_smallest(stack)->value;
	while (stacksize >= 0)
	{
		next_smallest = is_biggest(stack)->value;
		while(tmp->next != stack)
			tmp = index_pp(tmp,&next_smallest,&smallest);;
		tmp = index_pp(tmp,&next_smallest,&smallest);;
		smallest = next_smallest;
		stacksize--;
	}
	return(stack);
}

t_stack	*stack_setup(int argv,char *argc[],t_main *m_s)
{
	int			i;
	char	**strings;
	int			p;

	m_s->max = 0;
	p = 1;
	while(p < argv)
	{
		i = 0;
		strings = ft_split(argc[p], ' ');
		if(strings == NULL && strings[0] == NULL)
			my_error("ft_split failed");
		while (strings[i] != NULL)
		{
			if(check_for_valid_number(strings[i]) != 1)
				my_error("contains not allowed input");
			m_s->stack_a = add_stack(m_s->stack_a,ft_atoi(strings[i]));
			m_s->max++;
			free(strings[i]);
			i++;
		}
		if (m_s->max < 3)
			my_error("Stacksize to small\n");
		free(strings);
		p++;
	}
	return(add_index(m_s->stack_a,m_s->max));
}
