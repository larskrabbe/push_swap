/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:15:42 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/21 19:02:27 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"


/*
	struct to store value and the relativ position in the doppelt linked list

	int 	value -> the value that is stored in the struct
	t_stack *next -> the node next in the list
	t_stack *back -> the node before int the list
*/
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*back;
}t_stack;

/*
	Struct to store the top position of each struct

	t_stack *stack_a -> top position of stack a
	t_stack *stack_b -> top position of stack b
*/
typedef struct s_main
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}t_main;

/*
	Prints simple error message in red before exiting the porcess
	
	char *message -> error message that will be printed
*/
void my_error(char *message);

/*
	prints a stack in one line with spacec between it
	
	t_stack *stack -> the stack that will be printed
*/
void	print_stack(t_stack *stack);

/*
	turns the argumens in to doppel linked list

	int argv -> amount of argument that was passed with the exucutable 
	char *argc[] -> the string of number in the arguments
	t_stack *stack ->  the pointer to the stack to store everthing 
*/
t_stack	*stack_setup(int argv,char *argc[],t_stack *stack);


/*
	Swap the first 2 elements at the top of stack a
	Do nothing if there is only one or no elements

	t_stack *stack -> the current top position of the stack
	returns the new top position of the stack
*/
t_stack *swap(t_stack *stack);

/*
	swaps stack_a and stack_b at the same time.

	t_main m_s mian struct that stores both stacks
*/
void	swap_both(t_main *m_s);

/*
	pulls a top structer from a stack and fixed the pointer in it

	returns the structure
*/
t_stack *pull(t_stack *stack);