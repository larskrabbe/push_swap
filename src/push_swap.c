/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:57 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/11 15:11:33 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

int	main(int argv,char *argc[])
{
	t_both top;
	top.stack_a = NULL;
	top.stack_b = NULL;
	if (argv < 2)
		my_error("\nnot enough arguments", NULL);
	top.stack_a = stack_setup(argv,argc,&top);
	if (top.stack_a == NULL)
		return(0);
	if(!(is_small_big(top.stack_a) == 0 && is_smallest(top.stack_a, &top)))
		sort_stack(&top);
	free_two_stacks(&top);
	return (0);
}