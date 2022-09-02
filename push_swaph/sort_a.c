/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:50:37 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/02 20:52:49 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

void    a_b_sort(Stack **a, Stack **b, t_important *data, Actions action)
{
    if (data->length == 2)
    {
        if ((*a)->n > (*a)->next->n)
            action.sa(a, (*a)->next);
    }
    else if(data->length == 3)
        tripple(a);
    else if(data->length == 4)
        quadruple(a, b, data);
    else if(data->length == 5)
        quintuple(a, b, data);
    else if(data->length > 5)
        centuple(a, b, data, action);
}

void findhalf(Stack *tmp, Stack **b, int mx, int len)
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

int generate(int len)
{
    int chunk;

    if(chunk < 50)
        chunk = 3 + (len - 6) / 7;
    else if(chunk >= 50 && chunk < 100)
        chunk = 10 + (len - 50) / 8;
    else if(chunk >= 100 && chunk < 350)
        chunk = 18 + (len - 100) / 9;
    else if(chunk >= 350 && chunk <= 500)
        chunk = 27 + (len - 350) / 15;
    else if(chunk > 500)
        chunk = 37 + (len - 500) / 20;
    return chunk;
}
