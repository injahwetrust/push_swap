/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:00:00 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 15:01:08 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tri_2(t_stack *t)
{
	if (t->a[0] > t->a[1])
		sa(t);
}

void	tri_3(t_stack *t)
{
	if (t->a[0] > t->a[1] && t->a[1] < t->a[t->size_a - 1])
	{
		if (t->a[0] < t->a[t->size_a - 1])
			sa(t);
		else if (t->a[1] < t->a[t->size_a - 1])
			ra(t);
	}
	else if (t->a[0] > t->a[1] && t->a[1] > t->a[t->size_a - 1])
	{	
		sa(t);
		rra(t);
	}
	else if (t->a[0] < t->a[1])
	{
		if (t->a[0] < t->a[t->size_a - 1] && t->a[1] > t->a[t->size_a - 1])
		{
			sa(t);
			ra(t);
		}
		else if (t->a[0] > t->a[t->size_a - 1])
			rra(t);
	}
}

void	tri_5(t_stack *t)
{
	if (t->size_a == 5)
	{
		while (t->size_a != 3)
		{
			while (t->a[0] != 1 && t->a[0] != 2)
				ra(t);
			pb(t);
		}
		if (t->b[0] < t->b[1])
			sb(t);
	}
	if (t->size_a == 4)
	{
		while (t->a[0] != 1)
			ra(t);
		pb(t);
	}
	tri_3(t);
	while (t->size_b)
		pa(t);
}

void	tri_big(t_stack *t)
{
	quart_to_b(t);
	tri_3(t);
	pa(t);
	t->min = t->a[0];
	insert_b_to_a(t);
	end(t);
}
