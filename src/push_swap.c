/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 07:41:36 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 13:50:37 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pushswap_ab	*ab;
	char			next_move;
	char			state;

	if (argc < 2)
		return (0);
	ab = ft_pushswap_getinputs(argc, argv);
	if (!ab)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	state = ft_pushswap_isnotsorted(ab);
	while (state)
	{
		next_move = ft_pushswap_calcmove(ab, &state);
		ft_pushswap_printmove(next_move);
		ft_pushswap_domove(next_move, &ab);
	}
	free(ab->a);
	free(ab->b);
	free(ab);
	return (0);
}
