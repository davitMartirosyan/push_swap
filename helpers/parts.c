#include "../includes/header_push_swap.h"

void tripple(Stack **a)
{
    int n[3];
   
    n[0] = (*a)->n;
    n[1] = (*a)->next->n;
    n[2] = (*a)->next->next->n;

    if((n[0] == 1) && (n[1] == 0))
        sa(a, (*a)->next);
    else if((n[0] == 1) && (n[1] == 2))
        rra(a);
    else if((n[0] == 2) && (n[1] == 0))
        ra(a);
    else if((n[0] == 2) && (n[1] == 1))
    {
        ra(a);
        sa(a, (*a)->next);
    }
    if((n[0] == 0) && (n[1] == 2))
    {
        rra(a);
        sa(a, (*a)->next);
    }
}

void quadruple(Stack **a, Stack **b, t_important *data)
{
    int max;
    int step;
    Stack *tmp;

    max = data->length - 1;
    tmp = *a;
    step = -1;
    while(tmp->n != max)
        tmp = tmp->next;
    while(++step < tmp->idx)
        ra(a);
    pb(a, b);
    tripple(a);
    pa(a, b);
    ra(a);
}

void quintuple(Stack **a, Stack **b, t_important *data)
{
    int max;
    int step;
    int idx_c;
    Stack *tmp;

    tmp = *a;
    step = 2;
    max = data->length - 1;
    while(tmp->n != max && step > 0)
    {
        if(tmp->n == max)
        {
            idx_c = -1;
            while(++idx_c < tmp->idx)
                ra(a);
            pb(a, b);
            max--;
            step--;
        }
        tmp = tmp->next;
    }
    // ft_printf("5\n");
}

void centuple(Stack **a, Stack **b, t_important *data, Actions action)
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
            findhalf(tmp, b, len);
            action.pa(a, b);
            tmp = *b;
            mx--;
            len--;
            update_indacies(b);
        }
        else
            tmp = tmp->next;
    }  
}