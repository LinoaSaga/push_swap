/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algoturk_p2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:48:40 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 11:57:34 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sub functions specifically used in p2*/

/* search in the array the position of the highest int below n*/
/* if none is found, return the position of the highest int*/
void	ft_pushswap_sortturk_evalop_kb(t_pushswap_ab *ab, t_pushswap_nmove *nm)
{
	int		maxlow;
	size_t	pos_lm;
	size_t	k;

	pos_lm = -1;
	k = -1;
	maxlow = INT_MIN;
	while (++k < ab->nb)
	{
		if ((ab->a[nm->ka] > ab->b[k] && ab->b[k] > maxlow))
		{
			maxlow = ab->b[k];
			pos_lm = k;
		}
	}
	nm->kb = pos_lm;
	if (pos_lm == (size_t) -1)
		nm->kb = ft_pushswap_highestpos(ab->b, ab->nb);
}

/* Rotate a up and b down*/
void	ft_pushswap_sortturk_evalop_ud(t_pushswap_ab *ab, t_pushswap_nmove *nm)
{
	unsigned int	tot_op;

	tot_op = nm->ka + ab->nb - nm->kb;
	if (tot_op < nm->nb_op)
	{
		nm->nb_op = tot_op;
		if (nm->ka == 0)
			nm->n_move = 9;
		else
			nm->n_move = 5;
	}
}

/* Rotate a down and b up*/
void	ft_pushswap_sortturk_evalop_du(t_pushswap_ab *ab, t_pushswap_nmove *nm)
{
	unsigned int	tot_op;

	tot_op = ab->na - nm->ka + nm->kb;
	if (tot_op < nm->nb_op)
	{
		nm->nb_op = tot_op;
		if (nm->ka == 0)
			nm->n_move = 6;
		else
			nm->n_move = 8;
	}
}

/* Rotate a up and b up*/
void	ft_pushswap_sortturk_evalop_uu(t_pushswap_ab *ab, t_pushswap_nmove *nm)
{
	unsigned int	tot_op;

	(void) ab;
	tot_op = nm->ka;
	if (nm->kb > nm->ka)
		tot_op = nm->kb;
	if (tot_op < nm->nb_op)
	{
		nm->nb_op = tot_op;
		if (nm->ka == 0)
			nm->n_move = 6;
		else if (nm->kb == 0)
			nm->n_move = 5;
		else
			nm->n_move = 7;
	}	
}

/* Rotate a down and b down*/
void	ft_pushswap_sortturk_evalop_dd(t_pushswap_ab *ab, t_pushswap_nmove *nm)
{
	unsigned int	tot_op;

	tot_op = ab->na - nm->ka;
	if (ab->nb - nm->kb > ab->na - nm->ka)
		tot_op = ab->nb - nm->kb;
	if (tot_op < nm->nb_op)
	{
		nm->nb_op = tot_op;
		if (nm->ka == 0)
			nm->n_move = 9;
		else if (nm->kb == 0)
			nm->n_move = 8;
		else
			nm->n_move = 10;
	}	
}
