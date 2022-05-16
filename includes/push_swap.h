/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:28:44 by skhali            #+#    #+#             */
/*   Updated: 2022/05/16 04:49:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_move
{
	int	count;
} t_move;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

long	ft_atol(const char *str);
int	ft_abs(int value);

//Mouvements

void	rotate_a(t_stack **st);
void	rotate_b(t_stack **st);
void	rotate_r(t_stack **sta, t_stack **stb);
void	rrotate_a(t_stack **st);
void	rrotate_b(t_stack **st);
void	rrotate_r(t_stack **sta, t_stack **stb);
void	push_a(t_stack **st1, t_stack **st2);
void	push_b(t_stack **st1, t_stack **st2);
void	swap_a(t_stack **st);
void	swap_b(t_stack **st);

//Listes

t_stack	*ft_lstnew(int  value);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
int	lst_len(t_stack *list);
t_stack *ft_init_lst(char   **str);
void    free_lst(t_stack* list);

//Parsing
int	is_integer(char *str);
int is_singleton(char **str);
int	is_sorted(t_stack *list);
t_stack	*parsing(char **argv, int argc);

//Trie : de A vers B
t_stack	*get_mediane(t_stack *list);
t_stack	*get_max(t_stack *list);
int	get_min_index(t_stack *list);
void	first_sort(t_stack **stack_a, t_stack **stack_b);
void	second_sort(t_stack **stack_a, t_stack **stack_b);

//Trie : Trouver le nombre les moins couteux
int	sm_max(t_stack *stack_a, int value);
int	mv_count(t_stack *stack, int value);
t_stack *best_move(t_stack *s_b, t_stack *s_a);
void	move_el_to_a(t_stack **s_a, t_stack **s_b);
void slidetosort(t_stack **s_a);
void	move_b_to_a(t_stack **s_a, t_stack **s_b);

//Deplacer les nombres vers le haut à moindre couts
void	opti(t_stack *stack_a, t_stack *stack_b, int *rrr, int *rr);
void	move_up_a(t_stack **s_a, t_stack **s_b, t_stack *best);
void	move_up_b(t_stack **s_a, t_stack **s_b, t_stack *best);
void	move_up_both(t_stack **s_a, t_stack **s_b);

void	three_sort(t_stack **s_a);
void	four_sort(t_stack **s_a, t_stack **s_b);
void	five_sort(t_stack **s_a, t_stack **s_b);

#endif