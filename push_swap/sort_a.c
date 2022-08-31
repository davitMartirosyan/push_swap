/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:50:37 by dmartiro          #+#    #+#             */
/*   Updated: 2022/08/31 15:22:58 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"
void a_b_sort(Stack **a, Stack **b, t_important *data, Actions action)
{
    int mx;
    int len;
    Stack *tmp;
    
    b_fly(a, b, data, action);
    tmp = *b;
    mx = data->length - 1;
    len = data->length;
    while (tmp)
    {
        if (tmp->n == mx)
        {
            findhalf(tmp, b, mx, len);
            action.pa(a, b);
            tmp = *b;
            mx--;
            len--;
            update_indacies(b);
            update_indacies(a);
        }
        else
            tmp = tmp->next;
    }
}

void	findhalf(Stack *tmp, Stack **b, int mx, int len)
{
    if(tmp->idx <= (len / 2))
    {
        int step = -1;
        while(++step < (tmp->idx))
            rb(b);
    }
    else if(tmp->idx >= (len / 2))
    {
        int step = -1;
        while(++step < (len - tmp->idx))
            rrb(b);
    }
}
