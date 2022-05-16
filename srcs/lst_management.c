#include "../includes/push_swap.h"
#include "../includes/libft.h"

t_stack	*ft_lstnew(int  value)
{
	t_stack *cell;

    cell = (t_stack *)malloc(sizeof(t_stack));
	if (!cell)
		return (NULL);
	cell->value = value;
	cell->next = NULL;
	return (cell);
}

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack *copy;

	if (!alst)
		return ;
	copy = *alst;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	if (copy)
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}

int	lst_len(t_stack *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_stack *ft_init_lst(char   **str)
{
    t_stack *list;
    list = NULL;

    if(is_singleton(str))
    {
        while(*str)
        {
            if(is_integer(*str))
            {
                ft_lstadd_back(&list, ft_lstnew(atoi(*str)));
                str+= 1;
            }
            else {
                ft_putstr_fd("Error\n", 2);
                exit(EXIT_FAILURE);
            }
        }
    }
    else {
        ft_putstr_fd("Error\n", 2);
        exit(EXIT_FAILURE);
    }
    return (list);
}

void    free_lst(t_stack* list)
{
    t_stack* tmp;
    tmp = NULL;
    while(list)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}