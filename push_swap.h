/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:25:49 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 15:25:51 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	min;
	int	max;
}		t_stack;

typedef struct cmd
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	tot;
}		t_cmd;

int		*ft_index(int *tab, int size);
void	sa(t_stack *t);
void	sb(t_stack *t);
void	ss(t_stack *t);
void	pb(t_stack *t);
void	pa(t_stack *t);
void	ra(t_stack *t);
void	rb(t_stack *t);
void	rr(t_stack *t);
void	rra(t_stack *t);
void	rrb(t_stack *t);
void	rrr(t_stack *t);
void	init(t_cmd *cmd, int a);
void	rev_rotate(t_stack *t, t_cmd *cmd);
void	rotate(t_stack *t, t_cmd *cmd);
void	opti_quart(t_stack *t);
void	quart_to_b(t_stack *t);
t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int num);
t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int num);
t_cmd	best_rot(t_cmd cmd);
t_cmd	best_rev_rot(t_cmd cmd);
t_cmd	choose_best(t_cmd cmd, t_cmd cmd_best);
void	end(t_stack *t);
void	insert_b_to_a(t_stack *t);
void	tri_big(t_stack *t);
void	tri_5(t_stack *t);
void	tri_3(t_stack *t);
int		check_arg(int argc, char **argv);
int		is_sort(t_stack *t);
void	tri_2(t_stack *t);
t_stack	edit(int argc, char **argv);
void	clean(t_stack *t);
long	ft_atol(const char *nptr);

#endif
