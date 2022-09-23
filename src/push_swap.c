/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:57 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/22 22:51:25 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

int	main(int argv,char *argc[])
{
	t_main m_s;

	m_s.stack_a = NULL;
	m_s.stack_b = NULL;
	if (argv <= 3)
		my_error(" not enough arguments");
	m_s.stack_a = stack_setup(argv,argc,m_s.stack_a);
//	m_s.max = m_s.stack_a->back->num;
	print_stack((m_s.stack_a));
	print_stack((m_s.stack_b));
	// here will be start the sorting
	sort_stack(&m_s);
	print_stack((m_s.stack_a));
	print_stack((m_s.stack_b));
	return(0);
}