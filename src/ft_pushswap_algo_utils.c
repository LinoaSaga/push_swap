/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algo_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:20:06 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 14:29:15 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* function that return 0 if the list is sorted, 1 otherwise*/
char	ft_pushswap_isnotsorted(t_pushswap_ab *ab)
{
	size_t	k;

	if (ab->nb != 0)
		return (1);
	k = 0;
	while (++k < ab->na)
	{
		if (ab->a[k - 1] > ab->a[k])
			return (1);
	}
	return (0);
}

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

/* search in the array the position of the lowest int*/
size_t	ft_pushswap_lowestpos(int *x, size_t size)
{
	size_t	k;
	size_t	res;
	int		lowest;

	k = -1;
	lowest = INT_MAX;
	res = -1;
	while (++k < size)
	{
		if (x[k] < lowest)
		{
			lowest = x[k];
			res = k;
		}
	}
	return (res);
}

/* search in the array the position of the highest int*/
size_t	ft_pushswap_highestpos(int *x, size_t size)
{
	size_t	k;
	size_t	res;
	int		highest;

	k = -1;
	highest = INT_MIN;
	res = -1;
	while (++k < size)
	{
		if (x[k] > highest)
		{
			highest = x[k];
			res = k;
		}
	}
	return (res);
}
