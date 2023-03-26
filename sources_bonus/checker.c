/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:00:53 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/10 13:01:00 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../get_next_line.h"

t_stack	edit(int argc, char **argv)
{
	t_stack	t;

	t.size_a = 0;
	t.size_b = 0;
	t.a = malloc(sizeof(int) * (argc - 1));
	t.b = malloc(sizeof(int) * (argc - 1));
	if (!t.a || !t.b)
		return (t);
	while (t.size_a < argc - 1)
	{
		t.a[t.size_a] = ft_atol(argv[t.size_a + 1]);
		t.size_a++;
	}
	t.min = 0;
	t.max = t.size_a / 2;
	return (t);
}

void	exec_commands(t_stack *t, int nb, char c)
{
	if (nb == 211 && c == 'r')
		ra(t);
	else if (nb == 212 && c == 'r')
		rb(t);
	else if (nb == 325 && c == 'r')
		rra(t);
	else if (nb == 326 && c == 'r')
		rrb(t);
	else if (nb == 210 && c == 'p')
		pb(t);
	else if (nb == 209 && c == 'p')
		pa(t);
	else if (nb == 212 && c == 's')
		sa(t);
	else if (nb == 213 && c == 's')
		sb(t);
	else if (nb == 230 && c == 's')
		ss(t);
	else if (nb == 228 && c == 'r')
		rr(t);
	else if (nb == 342 && c == 'r')
		rrr(t);
	else
		write (2, "error\n", 6);
}

void	read_commands(t_stack *t)
{
	int		i;
	int		nb;
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		i = 0;
		nb = 0;
		while (str[i] != '\n')
		{
			nb += str[i];
			i++;
		}
		exec_commands(t, nb, str[0]);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (argc >= 2)
	{
		t = edit(argc, argv);
		if (check_arg(argc, argv))
			return (clean(&t));
		if (!t.a || !t.b)
			return (clean(&t));
		if (is_sort(&t) == 6)
			return (clean(&t));
		read_commands(&t);
		if (is_sort(&t) && t.size_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clean(&t);
	}
	return (0);
}
