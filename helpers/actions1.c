/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:05:03 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 19:05:54 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (*b == NULL)
		return ;
	t = *b;
	*b = (*b)->next;
	t->next = *a;
	*a = t;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (*a == NULL)
		return ;
	t = *a;
	*a = (*a)->next;
	t->next = *b;
	*b = t;
	ft_printf("pb\n");
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (check_stack_length(*a) < 1)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (check_stack_length(*b) < 1)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
}
