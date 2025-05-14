/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:05:49 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/14 09:33:36 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_pa(t_pushswap_ab **ab)
{
	size_t	k;

	if ((*ab)->nb < 1)
		return ;
	k = -1;
	while (++k < (*ab)->na)
		(*ab)->a[k + 1] = (*ab)->a[k];
	(*ab)->a[0] = (*ab)->b[0];
	k = 0;
	while (++k < (*ab)->nb)
		(*ab)->b[k - 1] = (*ab)->b[k];
	(*ab)->nb = (*ab)->nb - 1;
	(*ab)->na = (*ab)->na + 1;
}

void	ft_pushswap_pb(t_pushswap_ab **ab)
{
	size_t	k;

	if ((*ab)->na < 1)
		return ;
	k = -1;
	while (++k < (*ab)->nb)
		(*ab)->b[k + 1] = (*ab)->b[k];
	(*ab)->b[0] = (*ab)->a[0];
	k = 0;
	while (++k < (*ab)->na)
		(*ab)->a[k - 1] = (*ab)->a[k];
	(*ab)->na = (*ab)->na - 1;
	(*ab)->nb = (*ab)->nb + 1;
}

void	ft_pushswap_ra(t_pushswap_ab **ab)
{
	size_t	k;
	int		tmp;

	if ((*ab)->na < 2)
		return ;
	tmp = (*ab)->a[0];
	k = 0;
	while (++k < (*ab)->na)
		(*ab)->a[k - 1] = (*ab)->a[k];
	(*ab)->a[k - 1] = tmp;
}

void	ft_pushswap_rb(t_pushswap_ab **ab)
{
	size_t	k;
	int		tmp;

	if ((*ab)->nb < 2)
		return ;
	tmp = (*ab)->b[0];
	k = 0;
	while (++k < (*ab)->nb)
		(*ab)->b[k - 1] = (*ab)->b[k];
	(*ab)->b[k - 1] = tmp;
}

void	ft_pushswap_rr(t_pushswap_ab **ab)
{
	ft_pushswap_ra(ab);
	ft_pushswap_rb(ab);
}
