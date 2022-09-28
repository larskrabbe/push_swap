/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:57 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/09/26 15:36:04 by lkrabbe          ###   ########.fr       */
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
	ft_putnbr_fd(m_s.max,1);
	sort_stack(&m_s);
	return(0);
}