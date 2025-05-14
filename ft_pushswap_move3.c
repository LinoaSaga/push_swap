/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:06:31 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/14 12:32:09 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_rra(t_pushswap_ab **ab)
{
	size_t	k;
	int		tmp;

	if ((*ab)->na < 2)
		return ;
	tmp = (*ab)->a[(*ab)->na - 1];
	k = (*ab)->na + 1;
	while (--k > 0)
		(*ab)->a[k - 1] = (*ab)->a[k - 2];
	(*ab)->a[0] = tmp;
}

void	ft_pushswap_rrb(t_pushswap_ab **ab)
{
	size_t	k;
	int		tmp;

	if ((*ab)->nb < 2)
		return ;
	tmp = (*ab)->b[(*ab)->nb - 1];
	k = (*ab)->nb + 1;
	while (--k > 0)
		(*ab)->b[k - 1] = (*ab)->b[k - 2];
	(*ab)->b[0] = tmp;
}

void	ft_pushswap_rrr(t_pushswap_ab **ab)
{
	ft_pushswap_rra(ab);
	ft_pushswap_rrb(ab);
}
