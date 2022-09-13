/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:28:12 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/11 03:01:56 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

int	is_sorted(int *ints, int len)
{
	if (len == 1 || len == 0)
		return (1);
	if (ints[len - 1] < ints[len - 2])
		return (0);
	return (is_sorted(ints, len - 1));
}

void	b_fly(t_stack **a, t_stack **b, t_import *data)
{
	int	idx_c;
	int	chunk;

	chunk = generate(data->length);
	idx_c = 0;
	while ((*a) != NULL)
	{
		if ((*a)->n <= idx_c)
		{
			pb(a, b);
			rb(b);
			idx_c++;
		}
		else if ((*a)->n <= idx_c + chunk)
		{
			pb(a, b);
			idx_c++;
		}
		else
			ra(a);
	}
	update_indacies(b);
}

void	update_indacies(t_stack **tmp)
{
	t_stack	*temp;
	int		i;

	temp = *tmp;
	i = -1;
	while (temp)
	{
		temp->idx = ++i;
		temp = temp->next;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("{%d} : {%d}\n", tmp->idx, tmp->n);
		tmp = tmp->next;
	}
}
