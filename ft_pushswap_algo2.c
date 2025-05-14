/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algo2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:20:06 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/14 16:28:08 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* indicate the position of the first number in the array x*/
/* of size size, that is lower than the argument n*/
size_t	ft_pushswap_idealpos(int *x, size_t size, int n)
{
	size_t	res;

	res = 0;
	while (n > x[res] && res < size)
		res++;
	return (res);
}

/*verify that the first element is the lowest*/
char	ft_pushswap_islowestfirst(t_pushswap_ab *ab)
{
	size_t	k;

	k = 0;
	while (++k < ab->na)
	{
		if (ab->a[0] > ab->a[k])
			return (0);
	}
	return (1);
}

char	ft_pushswap_sortturk(t_pushswap_ab *ab, char *state)
{
	(void) ab;
	*state = 0;
	return (-1);
}
