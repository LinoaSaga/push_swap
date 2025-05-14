/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 07:41:36 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/14 09:48:25 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	main(int argc, char **argv)
{
	t_pushswap_ab	*ab;
	char			next_move;

	if (argc < 2)
		return (0);
	ab = ft_pushswap_getinputs(argc, argv);
	if (!ab)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	while (!ft_pushswap_issort(ab))
	{
		next_move = ft_pushswap_calcmove(ab);
		ft_pushswap_printmove(next_move);
		ft_pushswap_domove(next_move, &ab);
	}
	return (0);
} */

static void	ft_pushswap_printx(int *x, int nx)
{
	int	k;

	k = -1;
	while (++k < nx)
		ft_printf("%d\n", x[k]);
}

static void	ft_pushswap_printall(t_pushswap_ab *ab)
{
	ft_printf("a:\n");
	ft_pushswap_printx(ab->a, ab->na);
	ft_printf("b:\n");
	ft_pushswap_printx(ab->b, ab->nb);
}

/* trying inputs*/
int	main(int argc, char **argv)
{
	t_pushswap_ab	*ab;

	if (argc < 2)
		return (0);
	ab = ft_pushswap_getinputs(argc, argv);
	if (!ab)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	ft_pushswap_printall(ab);
}
