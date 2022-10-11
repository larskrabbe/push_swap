/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:57 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/10 08:41:03 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

int	main(int argv,char *argc[])
{
	t_both top;
	top.stack_a = NULL;
	top.stack_b = NULL;
	if (argv < 2)
		my_error(" \nnot enough arguments", NULL);
	top.stack_a = stack_setup(argv,argc,&top);
	sort_stack(&top);
	free_two_stacks(&top);
	return (0);
}