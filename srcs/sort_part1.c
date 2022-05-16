#include "../includes/push_swap.h"
#include "../includes/libft.h"


t_stack	*get_mediane(t_stack *list)
{
	t_stack *tmp;
	t_stack *first;
	int	cmp;
	int length;

	length = lst_len(list) / 2;
	first = list;
	while(list)
	{
		cmp = 0;
		tmp = first;
		while(tmp)
		{
			if(list->value < tmp->value)
				cmp++;
			tmp = tmp->next;
		}
		if(cmp == length)
			return (list);
		list = list->next;
	}
	return(ft_putstr_fd("Erreur\n", 1), exit(1), NULL);
}

t_stack	*get_max(t_stack *list)
{
	t_stack *max;

	max = list;
	list = list->next;
	while(list)
	{

		if(max->value < list->value)
			max = list;
		list = list->next;
	}
	return (max);
}

int	get_min_index(t_stack *list)
{
	int min;
	t_stack *suiv;
	t_stack *top;

	min = 0;
	top = list;
	suiv = list->next;
	while(suiv)
	{
		if(list->value > suiv->value)
			return (min+1);
		min++;
		list = list->next;
		suiv = suiv->next;
	}
	if(list->value > top->value)
		return (0);
	return (min);
}

void	first_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *mediane = get_mediane(*stack_a);
	t_stack *max = get_max(*stack_a);
	int length = lst_len(*stack_a);

	while(length)
	{
		if(((*stack_a)->value <= mediane->value) && ((*stack_a)->value != max->value))
			push_b(stack_b, stack_a);
		else
			rotate_a(stack_a);
		length--;
	}
}

void	second_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *max = get_max(*stack_a);
	int length = lst_len(*stack_a);

	while(length)
	{
		if((*stack_a)->value != max->value)
			push_b(stack_b, stack_a);
		else
			rotate_a(stack_a);
		length--;
	}
}