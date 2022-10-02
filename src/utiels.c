/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:31:33 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/02 01:13:46 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack *tmp;
	int 	i = 0;
	if (stack == NULL)
	{
		printf("Empty stack\n");
		return;
	}
	tmp = stack;
		printf("%i ",tmp->value);
	while(tmp->next != stack )
		{
			tmp = tmp->next;
			printf("%i ",tmp->value);
			i++;
		}
	printf("\n");
}

void	print_stack_index(t_stack *stack)
{
	t_stack *tmp;
	int 	i = 0;
	if (stack == NULL)
	{
		printf("Empty stack\n");
		return;
	}
	tmp = stack;
		printf("%i ",tmp->index);
	while(tmp->next != stack )
		{
			tmp = tmp->next;
			printf("%i ",tmp->index);
			i++;
		}
	printf("\n");
}

void	print_stack_reverse(t_stack *stack)
{
	t_stack *tmp;
	int 	i = 0;

	if (stack == NULL)
	{
		printf("Empty stack\n");
		return;
	}
	tmp = stack;
		printf("%i ",tmp->value);
	while(tmp->back != stack )
		{
			tmp = tmp->back;
			printf("%i ",tmp->value);
			i++;
		}
	printf("\n");
}

void print_struct_l_r(t_stack *stack)
{
			printf("	    back     <->   current  <->    next	\n");
			printf("value  |%6i     %10i     %10i\n",stack->back->value,stack->value,stack->next->value);
			printf("adress |\033[1;32m%p\033[1;0m \033[1;31m%p\033[1;0m \033[1;35m%p\033[1;0m\n",(void *)stack->back,(void *)stack,(void *)stack->next);
			printf("next   |\033[1;31m%p\033[1;0m \033[1;35m%p\033[1;0m %p\n",(void *)stack->back->next,(void *)stack->next,(void *)stack->next->next);
			printf("back   |%p \033[1;32m%p\033[1;0m \033[1;31m%p\033[1;0m\n",(void *)stack->back->back,(void *)stack->back,(void *)stack->next->back);
}
void	my_error(char *message)
{
	write(1,"Error :",8);
	printf(" \033[1;31m%s\033[1;0m\n",message);
	// he we need to free everthing
	exit(0);
}
