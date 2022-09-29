/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:57 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/29 14:20:28 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

int	main(int argv,char *argc[])
{
	t_main m_s;
	m_s.stack_a = NULL;
	m_s.stack_b = NULL;
	if (argv < 2)
		my_error(" \nnot enough arguments");
	m_s.stack_a = stack_setup(argv,argc,&m_s);
	// print_stack(m_s.stack_a);
	sort_stack(&m_s);
	// print_stack(m_s.stack_a);
	return(0);
}