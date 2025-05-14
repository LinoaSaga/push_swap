/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algo1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:18:58 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/14 16:22:22 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort list of 2*/
/* a simple swap if required*/
char	ft_pushswap_sort2(t_pushswap_ab *ab, char *state)
{
	if (ab->a[0] < ab->a[1])
	{
		*state = 0;
		return (-1);
	}
	else
		return (0);
}

/* sort list of 3*/
/* 6 different possibilites, handle case by case*/
/* 2 permutations at max*/
char	ft_pushswap_sort3(t_pushswap_ab *ab, char *state)
{
	if (ab->a[0] < ab->a[1] && ab->a[1] < ab->a[2])
	{
		*state = 0;
		return (-1);
	}
	else if (ab->a[0] > ab->a[1] && ab->a[1] > ab->a[2])
		return (0);
	else if (ab->a[0] < ab->a[1] && ab->a[1] > ab->a[2] && ab->a[2] > ab->a[0])
		return (0);
	else if (ab->a[0] < ab->a[1] && ab->a[1] > ab->a[2] && ab->a[2] < ab->a[0])
		return (8);
	else if (ab->a[0] > ab->a[1] && ab->a[1] < ab->a[2] && ab->a[2] > ab->a[0])
		return (0);
	else
		return (5);
}

/* sub function for the p3, due to line limits*/
char	ft_pushswap_sort4_p3(t_pushswap_ab *ab, char *state)
{
	size_t	ideal_pos_b;

	ideal_pos_b = ft_pushswap_idealpos(ab->a, ab->na, ab->b[0]);
	if (ideal_pos_b == 0 || ideal_pos_b == 3)
	{
		*state = 4;
		return (3);
	}
	return (5);
}

/* sort list of 4*/
/* not really optmised but algorithm complexity not eval on 4*/
/* 4 phases :*/
/* 1 we push an element in b*/
/* 2 we sort the 3 elements in a*/
/* 3 we rotate until we can push the last element at his place in a*/
/* 4 we rotate a until lowest in first position*/
char	ft_pushswap_sort4(t_pushswap_ab *ab, char *state)
{
	char	res;

	if (*state == 1)
	{
		*state = 2;
		return (4);
	}
	else if (*state == 2)
	{
		res = ft_pushswap_sort3(ab, state);
		if (*state == 0)
			*state = 3;
		return (res);
	}
	else if (*state == 3)
		return (ft_pushswap_sort4_p3(ab, state));
	else
	{
		if (ft_pushswap_idealpos(ab->a, ab->na, ab->a[0]) == 0)
		{
			*state = 0;
			return (-1);
		}
		return (5);
	}
}

/* main algo only work for 5 or more arguments*/
/* handle other cases with small specific algos*/
char	ft_pushswap_calcmove(t_pushswap_ab *ab, char *state)
{
	size_t	n;

	n = ab->na + ab->nb;
	if (n == 1)
	{
		*state = 0;
		return (-1);
	}
	else if (n == 2)
		return (ft_pushswap_sort2(ab, state));
	else if (n == 3)
		return (ft_pushswap_sort3(ab, state));
	else if (n == 4)
		return (ft_pushswap_sort4(ab, state));
	else
		return (ft_pushswap_sortturk(ab, state));
}
