/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:50:37 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 19:50:53 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	a_b_sort(t_stack **a, t_stack **b, t_import *data, t_actions action)
{
	if (data->length == 2)
	{
		if ((*a)->n > (*a)->next->n)
			action.sa(a, (*a)->next);
	}
	else if (data->length == 3)
		tripple(a);
	else if (data->length == 4)
		quadruple(a, b, data);
	else if (data->length == 5)
		quintuple(a, b, data);
	else if (data->length > 5)
		centuple(a, b, data, action);
}

void	findhalf(t_stack *tmp, t_stack **b, int len, char s)
{
	int	step;

	if (tmp->idx <= (len / 2))
	{
		step = -1;
		while (++step < (tmp->idx))
		{
			if (s == 'a')
				ra(b);
			else
				rb(b);
		}
	}
	else if (tmp->idx >= (len / 2))
	{
		step = -1;
		while (++step < (len - tmp->idx))
		{
			if (s == 'a')
				rra(b);
			else
				rrb(b);
		}
	}
}

int	generate(int len)
{
	int	chunk;

	chunk = 1;
	if (len < 50)
		chunk = 3 + (len - 6) / 7;
	else if (len >= 50 && len < 100)
		chunk = 10 + (len - 50) / 8;
	else if (len >= 100 && len < 350)
		chunk = 18 + (len - 100) / 9;
	else if (len >= 350 && len <= 500)
		chunk = 27 + (len - 350) / 15;
	else if (len > 500)
		chunk = 37 + (len - 500) / 20;
	return (chunk);
}
