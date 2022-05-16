#include "../includes/push_swap.h"

void	opti(t_stack *s_a, t_stack *s_b, int *rrr, int *rr)
{
	t_stack *best;
	int	count_a;
	int count_b;

	best = best_move(s_b, s_a);
	count_b = mv_count(s_b, best->value);
	count_a = mv_count(s_a, sm_max(s_a, best->value));

	if((count_a < 0) && (count_b < 0))
	{
		if (count_a < count_b)
			*rrr = count_a * (-1);
		else
			*rrr = count_b * (-1);
	}
	if((count_a > 0) && (count_b > 0))
	{
		if (count_a > count_b)
			*rr = count_a;
		else
			*rr = count_b;
	}
}
void	move_up_a(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	int	rot;
	int rr;
	int rrr;

	rr = 0;
	rrr = 0;
	opti(*s_a, *s_b, &rrr, &rr);
	rot = mv_count(*s_a, sm_max(*s_a, best->value));
	if(rot > 0)
	{
		rot -= rr;
		while(rot--)
			rotate_a(s_a);
	}
	else if (rot < 0)
	{
		rot = ft_abs(rot) - rr;
		while(rot--)
			rrotate_a(s_a);
	}
}
void	move_up_b(t_stack **s_a, t_stack **s_b, t_stack *best)
{
	int	rot;
	int rr;
	int rrr;

	rr = 0;
	rrr = 0;
	opti(*s_a, *s_b, &rrr, &rr);
	rot = mv_count(*s_b, best->value);
	if(rot > 0)
	{
		rot -= rr;
		while(rot--)
			rotate_b(s_b);
	}
	else if (rot < 0)
	{
		rot = ft_abs(rot) - rr;
		while(rot--)
			rrotate_b(s_b);
	}
}
void	move_up_both(t_stack **s_a, t_stack **s_b)
{
	int rr;
	int rrr;

	rr = 0;
	rrr = 0;
	opti(*s_a, *s_b, &rrr, &rr);
	while(rrr--)
		rrotate_r(s_a, s_b);
	while(rr--)
		rotate_r(s_a, s_b);
}