/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_push_swap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:20:43 by dmartiro          #+#    #+#             */
/*   Updated: 2022/09/13 20:09:33 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PUSH_SWAP_H
# define HEADER_PUSH_SWAP_H
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	long int		n;
	int				idx;
	struct s_stack	*next;
}	t_stack;

typedef struct s_important
{
	int		size;
	int		length;
	int		*collection_of_ints;
	char	*collection;
	char	**split;
}	t_import;

//parser functions
void		stack_nums_counter(char **av, t_import *data);
void		collect(char **av, t_import *data);
void		store(t_stack **a, t_import *data);

//Helpers
void		collecting_ints(t_import *data);
void		__sorted__indacies(t_import *data);
void		___bubble___(long int *arrtmp, int length);
void		__store__(t_import *data);
int			is_sorted(int *ints, int len);
int			__repeats__(t_import *data);
int			__check__collection(t_import *data);
int			check_stack_length(t_stack *stack);

void		update_indacies(t_stack **tmp);
void		print_stack(t_stack *stack);

//Error functions
int			errno(void);

//sorting algorithm functions
void		a_b_sort(t_stack **a, t_stack **b, t_import *d);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a, t_stack *x);
void		sb(t_stack **b, t_stack *x);
void		ss(t_stack **a, t_stack *x, t_stack **b, t_stack *y);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		b_fly(t_stack **a, t_stack **b, t_import *d);
void		findhalf(t_stack *tmp, t_stack **b, int len, char s);
int			generate(int len);

//sorting parts
void		tripple(t_stack **a);
void		quadruple(t_stack **a, t_stack **b, t_import *data);
void		quintuple(t_stack **a, t_stack **b, t_import *data);
void		centuple(t_stack **a, t_stack **b, t_import *d);
void		to_a(t_stack **a, t_stack **b);

#endif
