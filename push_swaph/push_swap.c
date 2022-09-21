/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:29:13 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/21 11:15:30 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_import	*data;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (-1);
	data = malloc(sizeof(*data));
	stack_nums_counter(av, data);
	collect(av, data);
	if (!__check__collection(data))
		errno();
	if (is_sorted(data->collection_of_ints, data->length))
		return (0);
	collecting_ints(data);
	store(&a, data);
	a_b_sort(&a, &b, data);
	return (0);
}
