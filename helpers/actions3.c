/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:10:24 by dmartiro          #+#    #+#             */
/*   Updated: 2022/08/22 13:50:04 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void rra(Stack **a)
{
    Stack *pen;
    Stack *last;
    Stack *first;
    
    pen = *a;
    last = *a;
    first = *a;
    while(pen->next->next != NULL) pen = pen->next;
    while(last->next != NULL) last = last->next;
    
    last->next = first;
    pen->next = NULL;
    *a = last;
    ft_printf("rra\n");
}

void rrb(Stack **b)
{
    Stack *pen;
    Stack *last;
    Stack *first;

    pen = *b;
    last = *b;
    first = *b;
    while(pen->next->next != NULL) pen = pen->next;
    while(last->next != NULL) last = last->next;
    
    last->next = first;
    pen->next = NULL;
    *b = last;
    ft_printf("rrb\n");
}

void rrr(Stack **a, Stack **b)
{
    rra(a);
    rrb(b);
    ft_printf("rrr\n");
}

Stack *ln(Stack **x)
{
    Stack *ls;

    ls = *x;
    while(ls->next != NULL) ls = ls->next;
    return (ls);
}