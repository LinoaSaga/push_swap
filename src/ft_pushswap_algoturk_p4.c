/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algoturk_p4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:21:08 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 11:57:35 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sub functions specifically used in p4*/

size_t	ft_pushswap_sortturk_p4core(t_pushswap_ab *ab)
{
	int		lowmax;
	size_t	pos_lm;
	size_t	k;

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
	if (pos_lm == (size_t) -1)
		pos_lm = ft_pushswap_lowestpos(ab->a, ab->na);
	return (pos_lm);
}
