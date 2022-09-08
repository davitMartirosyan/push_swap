/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:44:36 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/08 18:41:59 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	tripple(t_stack **a)
{
	int	n[3];

	n[0] = (*a)->n;
	n[1] = (*a)->next->n;
	n[2] = (*a)->next->next->n;
	if ((n[0] == 1) && (n[1] == 0))
		sa(a, (*a)->next);
	else if ((n[0] == 1) && (n[1] == 2))
		rra(a);
	else if ((n[0] == 2) && (n[1] == 0))
		ra(a);
	else if ((n[0] == 2) && (n[1] == 1))
	{
		ra(a);
		sa(a, (*a)->next);
	}
	if ((n[0] == 0) && (n[1] == 2))
	{
		rra(a);
		sa(a, (*a)->next);
	}
}

void	quadruple(t_stack **a, t_stack **b, t_import *data)
{
	int		max;
	int		step;
	t_stack	*tmp;

	max = data->length - 1;
	tmp = *a;
	step = -1;
	while (tmp->n != max)
		tmp = tmp->next;
	while (++step < tmp->idx)
		ra(a);
	pb(a, b);
	tripple(a);
	pa(a, b);
	ra(a);
}

void	quintuple(t_stack **a, t_stack **b, t_import *data)
{
	int		max;
	int		len;
	int		steps;
	t_stack	*tmp;

	max = data->length - 1;
	len = data->length + 1;
	steps = 2;
	tmp = (*a);
	while (tmp && steps)
	{
		if (tmp->n == max)
		{
			findhalf(tmp, a, --len, 'a');
			pb(a, b);
			tmp = *a;
			max--;
			steps--;
			update_indacies(a);
		}
		else
			tmp = tmp->next;
	}
	to_a(a, b);
}

void	to_a(t_stack **a, t_stack **b)
{
	tripple(a);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
}

void	centuple(t_stack **a, t_stack **b, t_import *data)
{
	int		mx;
	int		len;
	t_stack	*tmp;

	b_fly(a, b, data);
	tmp = *b;
	mx = data->length - 1;
	len = data->length;
	while (tmp)
	{
		if (tmp->n == mx)
		{
			findhalf(tmp, b, len, 'b');
			pa(a, b);
			tmp = *b;
			mx--;
			len--;
			update_indacies(b);
		}
		else
			tmp = tmp->next;
	}
}
