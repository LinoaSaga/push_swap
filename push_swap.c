/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 07:41:36 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/13 14:59:50 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
		ft_pushswap_domove(next_move, ab);
	}
	return (0);
}

/* trying inputs*/
/* int	main(int argc, char **argv)
{
	t_pushswap_ab	*ab;
	int				k;

	if (argc < 2)
		return (0);
	ab = ft_pushswap_getinputs(argc, argv);
	if (!ab)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	k = -1;
	while (++k < argc - 1)
		ft_printf("%d\n", ab->a[k]);
	return (0);
} */
