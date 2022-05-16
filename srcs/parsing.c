/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 01:04:24 by skhali            #+#    #+#             */
/*   Updated: 2022/05/15 23:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

#include <stdio.h>
int	is_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	i--;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

int is_singleton(char **str)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while(str[++i])
	{
		while(str[++j])
			if(atoi(str[i]) == atoi(str[j]))
				return (0);
		j = i + 1;
	}
	return (1);
}


int	is_sorted(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*next;

	cur = stack;
	while (cur)
	{
		next = cur->next;
		if (next && cur->value > next->value)
			return (0);
		cur = next;
	}
	return (1);
}

void	free_split(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
t_stack	*parsing(char **argv, int argc)
{
	t_stack	*stack;
	char **str;
	stack = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2){
		str = ft_split(argv[1], ' ');
		stack = ft_init_lst(str);
		free_split(str);
	}
	else
		stack = ft_init_lst(++argv);

	return (stack);
}