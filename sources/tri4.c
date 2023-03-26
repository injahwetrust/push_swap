/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:25 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 15:04:35 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init(t_cmd *cmd, int a)
{
	cmd->ra = a;
	cmd->rb = a;
	cmd->rra = a;
	cmd->rrb = a;
	cmd->tot = a * 2;
}

void	rev_rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->rra && cmd->rrb)
	{
		rrr(t);
		cmd->rra--;
		cmd->rrb--;
	}
	while (cmd->rra)
	{
		rra(t);
		cmd->rra--;
	}
	while (cmd->rrb)
	{
		rrb(t);
		cmd->rrb--;
	}
}

void	rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->ra && cmd->rb)
	{
		rr(t);
		cmd->ra--;
		cmd->rb--;
	}
	while (cmd->ra)
	{
		ra(t);
		cmd->ra--;
	}
	while (cmd->rb)
	{
		rb(t);
		cmd->rb--;
	}
}

t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int num)
{
	int	i;
	int	pos_a;

	pos_a = -1;
	i = 0;
	if (num < t->a[0] && num > t->a[t->size_a - 1])
		pos_a = 0;
	while (i < t->size_a && pos_a != 0)
	{
		if (num < t->min && t->a[i] == t->min)
			pos_a = i;
		else if (num > t->a[i] && num < t->a[i + 1] && i < t->size_a - 1)
			pos_a = i + 1;
		i++;
	}
	if (pos_a > t->size_a / 2)
		cmd.rra = t->size_a - pos_a;
	else
		cmd.ra = pos_a;
	return (cmd);
}

t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int num)
{
	int	i;

	i = 0;
	while (t->b[i] != num)
		i++;
	if (i > t->size_b / 2)
		cmd.rrb = t->size_b - i;
	else
		cmd.rb = i;
	return (cmd);
}
