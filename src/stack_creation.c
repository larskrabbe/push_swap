/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:35 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/23 19:21:01 by lkrabbe          ###   ########.fr       */
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

int	check_for_valid_number(char *str)
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


t_stack	*stack_setup(int argv,char *argc[],t_stack *stack)
{
	int		i;

	i = 1;
	while(argv > i)
	{
		if(check_for_valid_number(argc[i]) == 1)
			my_error("contains not allowed input");
		stack = add_stack(stack,ft_atoi(argc[i]));//need to check if the inout is valid
		i++;
	}
	return(stack);
}

// t_stack	*stack_setup(char *argc,t_stack *stack)
// {
// 	int		i;
// 	char **ptr;
	
// 	i = 0;
// 	ptr = ft_split(argc,' ');
// 	while(ptr[i] != NULL)
// 	{
// 		stack = add_stack(stack,ft_atoi(ptr[i]));//need to check if the inout is valid
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	return(stack);
// }
 
