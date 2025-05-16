/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algoturk1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:29:05 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/16 11:53:44 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sub p2 function to evaluate the min number of operations*/
/* to push element k in b at the correct place*/
/* we determine the element in b that should be first*/
/* then determine the best rotate operations to do*/
t_pushswap_nmove	ft_pushswap_sortturk_evalop(t_pushswap_ab *ab, size_t k)
{
	t_pushswap_nmove	res;

	res.ka = k;
	ft_pushswap_sortturk_evalop_kb(ab, &res);
	res.nb_op = -1;
	res.n_move = -1;
	if (res.ka == 0 && res.kb == 0)
	{
		res.nb_op = 0;
		res.n_move = 4;
		return (res);
	}
	ft_pushswap_sortturk_evalop_ud(ab, &res);
	ft_pushswap_sortturk_evalop_du(ab, &res);
	ft_pushswap_sortturk_evalop_uu(ab, &res);
	ft_pushswap_sortturk_evalop_dd(ab, &res);
	return (res);
}

/* p2 : pushing in b in correct order until 3 left in a*/
/* we calculate for each element the number of operations*/
/* to put it at it s right place in b, then*/
char	ft_pushswap_sortturk_p2(t_pushswap_ab *ab, char *state)
{
	t_pushswap_nmove	res;
	t_pushswap_nmove	info_k;
	size_t				k;

	if (ab->na == 3)
	{
		*state = 3;
		return (-1);
	}
	k = -1;
	while (++k < ab->na)
	{
		info_k = ft_pushswap_sortturk_evalop(ab, k);
		if (k == 0 || info_k.nb_op < res.nb_op)
			res = info_k;
	}
	return (res.n_move);
}

/* p4 : push everything in a at its correct place*/
/* if b is empty, we go p5*/
/* else, we calculate the position of the number directly superior*/
/* to what we re trying to insert, and rotate until it s in first*/
char	ft_pushswap_sortturk_p4(t_pushswap_ab *ab, char *state)
{
	int		lowmax;
	size_t	pos_lm;
	size_t	k;

	if (ab->nb == 0)
	{
		*state = 5;
		return (-1);
	}
	pos_lm = -1;
	k = -1;
	lowmax = INT_MAX;
	while (++k < ab->na)
	{
		if ((ab->b[0] < ab->a[k] && ab->a[k] < lowmax))
		{
			lowmax = ab->a[k];
			pos_lm = k;
		}
	}
	ft_printf("%d", pos_lm);
	if (pos_lm == 0)
		return (3);
	else if (pos_lm < ab->na / 2)
		return (5);
	else
		return (8);
}

/* p5 : rotate a until we have the first elem on top*/
/* calculate the position of the lowest number*/
/* rotate in a sense or the other depending on what is faster*/
char	ft_pushswap_sortturk_p5(t_pushswap_ab *ab, char *state)
{
	int		lowest;
	size_t	pos_lowest;
	size_t	k;

	lowest = ab->a[0];
	pos_lowest = 0;
	k = 0;
	while (++k < ab->na)
	{
		if (ab->a[k] < lowest)
		{
			lowest = ab->a[k];
			pos_lowest = k;
		}
	}
	if (pos_lowest == 0)
	{
		*state = 0;
		return (-1);
	}
	else if (pos_lowest < ab->na / 2)
		return (5);
	else
		return (8);
}

/* 5 phases*/
/* p1 : push 2 numbers in b*/
/* p2 : cf dedicated function, pushing in b in correcter order*/
/* until 3 left in a*/
/* p3 : sort the 3 numbers in a*/
/* p4 : cf dedicated function, push everything in a at its correct place*/
/* p5 : cf dedicated function, rotate a until we have the first elem on top*/
char	ft_pushswap_sortturk(t_pushswap_ab *ab, char *state)
{
	char	res;

	if (*state == 1)
	{
		if (ab->nb == 1)
			*state = 2;
		return (4);
	}
	else if (*state == 2)
		return (ft_pushswap_sortturk_p2(ab, state));
	else if (*state == 3)
	{
		res = ft_pushswap_sort3(ab, state);
		if (*state == 0)
			*state = 4;
		return (res);
	}
	else if (*state == 4)
		return (ft_pushswap_sortturk_p4(ab, state));
	else
		return (ft_pushswap_sortturk_p5(ab, state));
}
