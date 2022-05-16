#include "../includes/push_swap.h"

int	sm_max(t_stack *stack_a, int value)
{
	int s_max;
	s_max = get_max(stack_a)->value;
	while(stack_a)
	{
		if ((stack_a->value > value) && (s_max >= stack_a->value))
		{
			s_max = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	return(s_max);
}

int	mv_count(t_stack *stack, int value)
{
	int count;
	int	length = lst_len(stack);
	int mid = length / 2;

	count = 0;
	while(stack->value != value)
	{
		count++;
		stack = stack->next;
	}
	if(mid < count)
	{
		count -= length;
	}
	return (count);
}

t_stack *best_move(t_stack *s_b, t_stack *s_a)
{
	t_stack *opticell;
	t_stack *top;
	int	count;
	int test;

	count = ft_abs(mv_count(s_b, s_b->value) + mv_count(s_a, sm_max(s_a, s_b->value)));
	opticell = s_b;
	top = s_b;
	test = 0;
	while(s_b)
	{
		test = ft_abs(mv_count(top, s_b->value)) + ft_abs(mv_count(s_a, sm_max(s_a, s_b->value)));
		if (test < count)
		{
			opticell = s_b;
			count = test;
		}
		s_b = s_b->next;
	}
	return (opticell);
}

void	move_el_to_a(t_stack **s_a, t_stack **s_b)
{
	t_stack *best;
	int	count_a;
	int count_b;

	best = best_move(*s_b, *s_a);
	count_b = mv_count(*s_b, best->value);
	if(best->value > get_max(*s_a)->value)
		count_a = get_min_index(*s_a);
	else
		count_a = mv_count(*s_a, sm_max(*s_a, best->value));
	if (count_b)
	{
		move_up_both(s_a, s_b);
		move_up_b(s_a, s_b, best);
	}
	if(count_a)
		move_up_a(s_a, s_b, best);
	push_a(s_b, s_a);
}

void	move_b_to_a(t_stack **s_a, t_stack **s_b)
{
	int	length = lst_len(*s_b);

	while(length--)
		move_el_to_a(s_a, s_b);
	
	slidetosort(s_a);
}

void slidetosort(t_stack **s_a)
{
	int	length;
	int min;
	int mid;
	int idk;

	length = lst_len(*s_a);
	min = get_min_index(*s_a);
	mid = length / 2;
	idk = length - min;

	if (!is_sorted(*s_a))
	{
		if(min < mid)
			while (min--)
				rotate_a(s_a);
		else
			while (idk--)
				rrotate_a(s_a);
	}
}