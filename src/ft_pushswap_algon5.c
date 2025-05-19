/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_algon5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:29:33 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 11:57:32 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_pushswap_sort5_p2(t_pushswap_ab *ab, char *state)
{
	if (ab->b[0] > ab->b[1])
	{
		*state = 3;
		return (-1);
	}
	else
		return (1);
}

/*chronologically, last algo made to be sure to stay below the threshold*/
/* with a 100% rate*/
/* similar to turkish, except p2 is a swap if required*/
char	ft_pushswap_sort5(t_pushswap_ab *ab, char *state)
{
	char	res;

	if (*state == 1)
	{
		if (ab->nb == 1)
			*state = 2;
		return (4);
	}
	else if (*state == 2)
		return (ft_pushswap_sort5_p2(ab, state));
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
