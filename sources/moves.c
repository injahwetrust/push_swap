/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:54:53 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 14:54:59 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *t)
{
	int	tmp;

	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
	write(1, "ss\n", 3);
}

void	pb(t_stack *t)
{
	int	i;
	int	stmp_b;

	i = 0;
	stmp_b = t->size_b;
	while (stmp_b > 0)
	{
		t->b[stmp_b] = t->b[stmp_b - 1];
		stmp_b--;
	}
	t->b[0] = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i++;
	}
	t->size_a -= 1;
	t->size_b += 1;
	write(1, "pb\n", 3);
}

void	pa(t_stack *t)
{
	int	i;
	int	stmp_a;

	i = 0;
	stmp_a = t->size_a;
	while (stmp_a > 0)
	{
		t->a[stmp_a] = t->a[stmp_a - 1];
		stmp_a--;
	}
	t->a[0] = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i++;
	}
	t->size_a += 1;
	t->size_b -= 1;
	write(1, "pa\n", 3);
}
