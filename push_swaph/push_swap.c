/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:29:13 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 22:09:02 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

int	main(int ac, char **av)
{
	t_actions	action;
	t_stack		*a;
	t_stack		*b;
	t_import	*data;

	if (ac < 2)
		return (-1);
	data = malloc(sizeof(*data));
	stack_nums_counter(av, data);
	collect(av, data);
	__check__collection(data);
	__collecting_ints(data);
	action = init();
	a = NULL;
	b = NULL;
	store(&a, data);
	a_b_sort(&a, &b, data, action);
	return (0);
}