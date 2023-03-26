/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:25 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 15:04:35 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	opti_quart(t_stack *t)
{
	int	i;

	i = 0;
	while (!(t->a[i] >= t->min && t->a[i] <= t->max) && i < t->size_a)
			i++;
	if (i > 0 && t->b[0] >= t->min
		&& t->b[0] <= (t->max + t->min) / 2 && t->size_b > 1)
		rr(t);
	if (t->b[0] >= t->min
		&& t->b[0] <= (t->max + t->min) / 2 && t->size_b > 1)
		rb(t);
}

void	quart_to_b(t_stack *t)
{
	int	save;

	save = t->size_a;
	while (t->size_a >= 3)
	{
		if (t->size_b == save / 2)
		{
			t->min = t->max;
			t->max = save - 3;
		}
		while (!(t->a[0] >= t->min && t->a[0] <= t->max))
			ra(t);
		pb(t);
		if (t->size_a == 3)
			break ;
		opti_quart(t);
	}
}
