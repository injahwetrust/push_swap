/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:02:05 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 15:03:05 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cmd	best_rot(t_cmd cmd)
{
	while (cmd.ra && cmd.rb)
	{
		cmd.ra--;
		cmd.rb--;
		cmd.tot++;
	}
	while (cmd.ra)
	{
		cmd.ra--;
		cmd.tot++;
	}
	while (cmd.rb)
	{
		cmd.rb--;
		cmd.tot++;
	}
	return (cmd);
}

t_cmd	best_rev_rot(t_cmd cmd)
{
	while (cmd.rra && cmd.rrb)
	{
		cmd.rra--;
		cmd.rrb--;
		cmd.tot++;
	}
	while (cmd.rra)
	{
		cmd.rra--;
		cmd.tot++;
	}
	while (cmd.rrb)
	{
		cmd.rrb--;
		cmd.tot++;
	}
	return (cmd);
}

t_cmd	choose_best(t_cmd cmd, t_cmd cmd_best)
{
	t_cmd	clone;

	clone = cmd;
	cmd = best_rot(cmd);
	cmd = best_rev_rot(cmd);
	clone.tot = cmd.tot;
	if (cmd_best.tot > cmd.tot)
		cmd_best = clone;
	return (cmd_best);
}

void	end(t_stack *t)
{
	if (t->a[0] <= t->size_a / 2 + 1)
		while (t->a[0] != 1)
			rra(t);
	else
		while (t->a[0] != 1)
			ra(t);
}

void	insert_b_to_a(t_stack *t)
{
	t_cmd	cmd_best;
	t_cmd	cmd;
	int		i;

	init(&cmd, 0);
	while (t->size_b)
	{
		init(&cmd_best, 100000);
		i = 0;
		while (i < t->size_b)
		{
			cmd = edit_command_a(t, cmd, t->b[i]);
			cmd = edit_command_b(t, cmd, t->b[i]);
			cmd_best = choose_best(cmd, cmd_best);
			i++;
			init(&cmd, 0);
		}
		rotate(t, &cmd_best);
		rev_rotate(t, &cmd_best);
		pa(t);
		if (t->a[0] < t->min)
			t->min = t->a[0];
	}
}
