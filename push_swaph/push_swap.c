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

static void cleanup(t_stack *a, t_stack *b, t_import *d);

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
	if(!__check__collection(data))
	{
		cleanup(a, b, data);
		errno("Error");
	}
	__collecting_ints(data);
	action = init();
	a = NULL;
	b = NULL;
	store(&a, data);
	a_b_sort(&a, &b, data, action);
	cleanup(a, b, data);
	return (0);
}

static void cleanup(t_stack *a, t_stack *b, t_import *d)
{
	t_stack *tmp;
	int i;

	tmp = a;
	while(a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	i = -1;
	while(d->split[++i])
		free(d->split[i]);
	free(d->split);
	free(d->collection_of_ints);
	free(d->collection);
	free(b);
	free(a);
}
