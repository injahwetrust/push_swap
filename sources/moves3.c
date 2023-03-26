/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:57:52 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 14:58:03 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack *t)
{
	int	tmp;
	int	size;

	size = t->size_a;
	tmp = t->a[size - 1];
	while (size > 1)
	{
		t->a[size - 1] = t->a[size - 2];
		size--;
	}
	t->a[0] = tmp;
	size = t->size_b;
	tmp = t->b[size - 1];
	while (size > 1)
	{
		t->b[size - 1] = t->b[size - 2];
		size--;
	}
	t->b[0] = tmp;
	write(1, "rrr\n", 4);
}
