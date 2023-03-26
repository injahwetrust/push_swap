/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <bvaujour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:37:41 by bvaujour          #+#    #+#             */
/*   Updated: 2023/01/18 17:46:51 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_arg(argc, argv))
		return (0);
	if (argc > 2)
	{
		t = edit(argc, argv);
		if (is_sort(&t) || !t.a || !t.b)
		{
			clean(&t);
			return (0);
		}
		if (argc == 3)
			tri_2(&t);
		if (argc == 4)
			tri_3(&t);
		if (argc > 4 && argc < 7)
			tri_5(&t);
		if (argc > 6)
			tri_big(&t);
		clean(&t);
	}
	return (0);
}
