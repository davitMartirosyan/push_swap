/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:06:07 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/07 19:05:54 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	sa(t_stack **a, t_stack *x)
{
	t_stack	*tmp;

	tmp = x->next;
	x->next = *a;
	(*a)->next = tmp;
	*a = x;
	ft_printf("sa\n");
}

void	sb(t_stack **b, t_stack *x)
{
	t_stack	*tmp;

	tmp = x->next;
	x->next = *b;
	(*b)->next = tmp;
	*b = x;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack *x, t_stack **b, t_stack *y)
{
	sa(a, x);
	sb(b, y);
}
