/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:15:42 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/20 18:22:43 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"libft.h"

//rules
# define SA "sa"	
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# ifndef BETTERERROR
#  define BETTERERROR 0
# endif

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
typedef struct s_both
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max;
}t_both;

/*
	Prints simple error message in red before exiting the porcess
	
	char *message -> error message that will be printed
*/
void			my_error(char *message, t_both *top);

/*
	prints a stack in one line with spacec between it

	t_stack *stack -> the stack that will be printed
*/
void			print_stack(t_stack *stack);

/*
	same as print_stack but in reverse way to check


*/
void			print_stack_reverse(t_stack *stack);

/*
	turns the argumens in to doppel linked list

	char *argc-> the string of number in the arguments
	t_stack *stack ->  the pointer to the stack to store everthing 
*/
t_stack			*stack_setup(int argv, char *argc[], t_both *top);

/*
	Swap the first 2 elements at the top of stack a
	Do nothing if there is only one or no elements

	t_stack *stack -> the current top position of the stack
	returns the new top position of the stack
*/
t_stack			*swap(t_stack *stack, t_both *top);

/*
	swaps stack_a and stack_b at the same time.

	t_both top mian struct that stores both stacks
*/
void			swap_both(t_both *top);

/*
	prints the address and values of the structe and the structur that 
	are conected with next and back
*/
void			print_struct_l_r(t_stack *stack);

/*
	rotate the stack in direction of next/forword

	t_stack stack -> top position of the stack
	returns -> returns the updated TOP position of the stack
*/
t_stack			*rotate(t_stack **stack, t_both *top);

/*
	rotate the stack in direction of back/backwards

	t_stack stack -> top position of the stack

	returns -> returns the updated TOP position of the stack
*/
t_stack			*reverse_rotate(t_stack **stack, t_both *top);

/**
 * @brief push the top struct of stack_pull on the top position of stack_insert
 * 
 * @param stack_insert stack to insert in
 * @param stack_pull stack to pull from
 */
void			push(t_stack **stack_insert, t_stack **stack_pull, t_both *top);

/*
	Choose the currect funktion to change the stacks depending on the rules 

	char *rule -> string to determen the select rule
	t_both *top -> main struct that contains the stacks 
*/
void			rules(char *rule, t_both *top);

/*
	main funktion for the sorting part


*/
void			sort_stack(t_both *top);

/**
 * @brief search in a stack for a member with a specific value
 * 
 * @param t_stack * stack -> target stack for looking for the value
 * @param int value -> value to look for
 */
t_stack			*look_for_value(t_stack *stack, int value);

void			print_stack_index(t_stack *stack);

t_stack			*is_smallest(t_stack *stack, t_both *top);
/**
 * @brief 
 * 
 */
t_stack			*is_biggest(t_stack *stack, t_both *top);

/**
 * @brief look for the position to insert the currrent 
 * struct inside of a stack
 * 
 * @param stack  stack to look for where insert would be placed
 * @param insert struct that looks for a place
 * 
 * @return returns the posisiton that would be next 
 * after insert would be inserted
 */
t_stack			*where_to_insert(t_stack *stack, t_stack *insert, t_both *top);

/**
 * @brief returns the size of the stack.
 * 
 * @param stack  Pointer to the top position of the stack
 * @return returns the length of the stack as a int
 */
int				stack_length(t_stack *stack);

/**
 * @brief "Pulls" the top structure form the stack and 
 * relinked the next and back pointer
 * 
 * @param stack stack tp pull from
 * 
 * @return returns the structure that was pulled
 */
t_stack			*pull(t_stack **stack, t_both *top);

/**
 * @brief frees every strucur in both stacks
 * 
 * @param top main structure that contains both stacks
 */
void			free_two_stacks(t_both *top);

/**
 * @brief Sort small stacks pretty decent
 * 
 * @param top main structure that stores both stacks
 */
void			quick_sort(t_both *top);

/**
 * @brief rotates the targert struct to the top of the stack(A)
 * 
 * @param top main structure that stores both stacks
 * @param target target that will be on top
 */
void			rotate_to_top_b(t_both *top, t_stack *target);

/**
 * @brief rotates the targert struct to the top of the stack(B)
 * 
 * @param top main structure that stores both stacks
 * @param target target that will be on top
 */
void			rotate_to_top_a(t_both *top, t_stack *target);

/**
 * @brief looks up if it faster to rotate forward or backwards to 
 * reach the target inside of the stack
 * 
 * @param stack the stack that can be rotated
 * @param target target inside of the stack
 */
int				r_or_rr(t_stack *stack, t_stack *target);

/**
 * @brief see what struct needs to be top to insert the target 
 * so that it will be in acending order. 
 * it will only works if the stack is already in acsending order 
 * but the smalles doesnt have to on top
 * @param stack the stack that will get inserted 
 * @param insert the struct that would be inserted
 * @return returns the struct that should be on top 
 */

void			chunk_sort(t_both *top);

/**
 * @brief check if it in acending order, not caring if it start at the smallest
 * 
 * 
 */
int				is_small_big(t_stack *stack_a);

/**
 * @brief check if the char is a equel to one of the whitespace charackter
 * 
 */
int				is_white_space(int a);

/**
 * @brief ft_atoi that returns a long int instead
 * 
 */
long long int	my_atoli(const char *str);

/**
 * @brief frees each string in a doppelt pointer
 * 
 */
void			free_strings(char **strings);

void			strings_to_struct(char **str, t_both *top, long long int num);
t_stack			*add_index(t_stack *stack, int stacksize, t_both *top);
void			check_input(char *str, t_both *top);

#endif