/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:10:24 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 19:05:54 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*pen;
	t_stack	*last;
	t_stack	*first;

	pen = *a;
	last = *a;
	first = *a;
	while (pen->next->next != NULL)
		pen = pen->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	pen->next = NULL;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*pen;
	t_stack	*last;
	t_stack	*first;

	pen = *b;
	last = *b;
	first = *b;
	while (pen->next->next != NULL)
		pen = pen->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	pen->next = NULL;
	*b = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

t_stack	*ln(t_stack **x)
{
	t_stack	*ls;

	ls = *x;
	while (ls->next != NULL)
		ls = ls->next;
	return (ls);
}
