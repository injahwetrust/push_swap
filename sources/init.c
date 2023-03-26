/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:58:22 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/07 14:59:27 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_arg(int argc, char **argv)
{
	int			i;
	int			j;
	long int	nb;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				return (write (2, "error\n", 6));
			j++;
		}
		nb = ft_atol(argv[i]);
		if (nb > 2147483647 || nb < -2147483648 || j > 11)
			return (write(2, "error\n", 6));
		i++;
	}
	return (0);
}

int	is_sort(t_stack *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->size_a - 1)
	{
		j = i + 1;
		while (j < t->size_a)
		{
			if (t->a[i] == t->a[j])
				return (write (2, "error\n", 6));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < t->size_a - 1)
	{
		if (t->a[i] > t->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
	t.a = ft_index(t.a, t.size_a);
	return (t);
}

void	clean(t_stack *t)
{
	free(t->a);
	free(t->b);
}

int	*ft_index(int *tab, int size)
{
	int	index;
	int	i;
	int	j;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i <= size - 1)
	{
		j = 0;
		index = 0;
		while (j <= size - 1)
		{
			if (tab[i] > tab[j])
				index++;
			j++;
		}
		tmp[i] = index + 1;
		i++;
	}
	free(tab);
	return (tmp);
}
