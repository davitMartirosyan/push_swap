/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:06:07 by dmartiro          #+#    #+#             */
/*   Updated: 2022/08/22 11:55:57 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void rr(Stack **a, Stack **b)
{
    ra(a);
    rb(b);
    ft_printf("rr\n");
}

void sa(Stack **a, Stack *x)
{
    Stack *tmp;
    
    tmp = x->next;
    x->next = *a;
    (*a)->next = tmp;
    *a = x;
    ft_printf("sa\n");
}

void sb(Stack **b, Stack *x)
{
    Stack *tmp;

    tmp = x->next;
    x->next = *b;
    (*b)->next = tmp;
    *b = x;
    ft_printf("sb\n");
}

void ss(Stack **a, Stack *x, Stack **b, Stack *y)
{
    sa(a, x);
    sb(b, y);
}