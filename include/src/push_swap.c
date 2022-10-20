/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:57 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/20 17:42:08 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

t_stack	*stack_setup(int argv, char *argc[], t_both *top)
{
	char			**strings;
	int				p;
	long long int	num;

	num = 0;
	top->max = 0;
	p = 1;
	while (p < argv)
	{
		check_input(argc[p], top);
		strings = ft_split(argc[p], ' ');
		if (strings == NULL)
			my_error("ft_split failed", top);
		if (strings[0] == NULL)
		{
			free_strings(strings);
			my_error("empty argument", top);
		}
		strings_to_struct(strings, top, num);
		free_strings(strings);
		p++;
	}
	return (add_index(top->stack_a, top->max, top));
}

int	main(int argv, char *argc[])
{
	t_both		top;

	top.stack_a = NULL;
	top.stack_b = NULL;
	if (argv < 2)
		my_error("\nnot enough arguments", NULL);
	top.stack_a = stack_setup(argv, argc, &top);
	if (top.stack_a == NULL)
		return (0);
	if (!(is_small_big(top.stack_a) == 0 && is_smallest(top.stack_a, &top)))
		sort_stack(&top);
	free_two_stacks(&top);
	return (0);
}
