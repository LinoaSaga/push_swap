/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algo2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:20:06 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/14 16:20:35 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* indicate the position of the first number in the array x*/
/* of size size, that is lower than the argument n*/
size_t	ft_pushswap_idealpos(int *x, size_t size, int n)
{
	size_t	res;

	res = 0;
	while (x[res] > n && res < size)
		res++;
	return (res);
}

char	ft_pushswap_sortturk(t_pushswap_ab *ab, char *state)
{
	(void) ab;
	*state = 0;
	return (-1);
}
