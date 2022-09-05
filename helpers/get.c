/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:28:12 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/01 15:35:33 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_push_swap.h"

int is_sorted(int *ints, int len)
{
    if(len == 1 || len == 0)
        return (1);
    if(ints[len - 1] < ints[len - 2])
        return (0);
    
    return is_sorted(ints, len - 1);
}

void b_fly(Stack **a, Stack **b, t_important *data, Actions action)
{
    int idx_c;
    int chunk;
    
    chunk = generate(data->length);
    idx_c = 0;
    while((*a) != NULL)
    {
        if((*a)->n <= idx_c)
        {
            action.pb(a, b);
            action.rb(b);
            idx_c++;
        }
        else if((*a)->n <= idx_c + chunk)
        {
            action.pb(a, b);
            idx_c++;
        }
        else
            action.ra(a);
    }
    update_indacies(b);
}

void update_indacies(Stack **tmp)
{
    Stack *temp = *tmp;
    int i = -1;
    while(temp)
    {
        temp->idx = ++i;
        temp = temp->next;
    }
}

void print_stack(Stack *stack)
{
    Stack *tmp = stack;
    while(tmp != NULL)
    {
        ft_printf("{%d} : {%d}\n", tmp->idx, tmp->n);
        tmp = tmp->next;
    }
    // ft_printf("\n");
}

Actions init(void)
{   
    Actions *init;

    init = (Actions *)malloc(sizeof(*init));
    init->pa = &pa;
    init->pb = &pb;
    init->sa = &sa;
    init->sb = &sb;
    init->ss = &ss;
    init->ra = &ra;
    init->rb = &rb;
    init->rr = &rr;
    init->rra = &rra;
    init->rrb = &rrb;
    init->rrr = &rrr;
    return (*init);
}