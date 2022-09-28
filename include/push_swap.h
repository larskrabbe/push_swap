/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:15:42 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/26 16:34:49 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
	struct to store value and the relativ position in the doppelt linked list

	int 	value -> the value that is stored in the struct
	int 	index -> the order of the values
	t_stack *next -> the node next in the list
	t_stack *back -> the node before int the list
*/
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*back;
}t_stack;

/*
	Struct to store the top position of each struct

	t_stack **stack_a -> top position of stack a
	t_stack **stack_b -> top position of stack b
*/
typedef struct s_main

#define SA "sa"	
#define SB "sb"
#define SS "ss"
#define PA "pa"
#define PB "pb"
#define RA "ra"
#define RB "rb"
#define RR "rr"
#define RRA "rra"
#define RRB "rrb"
#define RRR "rrr"

{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max;
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
	same as print_stack but in reverse way to check


*/
void	print_stack_reverse(t_stack *stack);

/*
	turns the argumens in to doppel linked list

	char *argc-> the string of number in the arguments
	t_stack *stack ->  the pointer to the stack to store everthing 
*/
t_stack	*stack_setup(int argv,char *argc[],t_main *m_s);

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
	prints the address and values of the structe and the structur that are conected with next and back




*/
void print_struct_l_r(t_stack *stack);

/*
	rotate the stack in direction of next/forword

	t_stack stack -> top position of the stack
	returns -> returns the updated TOP position of the stack
*/
t_stack	*rotate(t_stack **stack);

/*
	rotate the stack in direction of back/backwards

	t_stack stack -> top position of the stack

	returns -> returns the updated TOP position of the stack
*/
t_stack	*reverse_rotate(t_stack **stack);

/*
	Choose the currect funktion to change the stacks depending on the rules 

	char *rule -> string to determen the select rule
	t_main *m_s -> main struct that contains the stacks 
*/
void	rules(char *rule,t_main *m_s);

/*
	main funktion for the sorting part


*/
void	sort_stack(t_main *a_s);

/**
 * @brief search in a stack for a member with a specific value
 * 
 * @param t_stack * stack -> target stack for looking for the value
 * @param int value -> value to look for
 */
t_stack	*look_for_value(t_stack *stack,int value);

void	print_stack_index(t_stack *stack);

t_stack *is_smallest(t_stack *stack);
/**
 * @brief 
 * 
 */
t_stack *is_biggest(t_stack *stack);
/**
 * @brief returns the size of the stack.
 * 
 * @param stack  Pointer to the top position of the stack
 * @return returns the length of the stack as a int
 */
int stack_length(t_stack *stack);
