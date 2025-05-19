/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:06:28 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 11:57:40 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap_printmove(char move)
{
	if (move == 0)
		ft_putstr_fd("sa\n", 1);
	else if (move == 1)
		ft_putstr_fd("sb\n", 1);
	else if (move == 2)
		ft_putstr_fd("ss\n", 1);
	else if (move == 3)
		ft_putstr_fd("pa\n", 1);
	else if (move == 4)
		ft_putstr_fd("pb\n", 1);
	else if (move == 5)
		ft_putstr_fd("ra\n", 1);
	else if (move == 6)
		ft_putstr_fd("rb\n", 1);
	else if (move == 7)
		ft_putstr_fd("rr\n", 1);
	else if (move == 8)
		ft_putstr_fd("rra\n", 1);
	else if (move == 9)
		ft_putstr_fd("rrb\n", 1);
	else if (move == 10)
		ft_putstr_fd("rrr\n", 1);
}

void	ft_pushswap_domove(char move, t_pushswap_ab **ab)
{
	if (move == 0)
		ft_pushswap_sa(ab);
	else if (move == 1)
		ft_pushswap_sb(ab);
	else if (move == 2)
		ft_pushswap_ss(ab);
	else if (move == 3)
		ft_pushswap_pa(ab);
	else if (move == 4)
		ft_pushswap_pb(ab);
	else if (move == 5)
		ft_pushswap_ra(ab);
	else if (move == 6)
		ft_pushswap_rb(ab);
	else if (move == 7)
		ft_pushswap_rr(ab);
	else if (move == 8)
		ft_pushswap_rra(ab);
	else if (move == 9)
		ft_pushswap_rrb(ab);
	else if (move == 10)
		ft_pushswap_rrr(ab);
}

void	ft_pushswap_sa(t_pushswap_ab **ab)
{
	int	tmp;

	if ((*ab)->na < 2)
		return ;
	tmp = (*ab)->a[0];
	(*ab)->a[0] = (*ab)->a[1];
	(*ab)->a[1] = tmp;
}

void	ft_pushswap_sb(t_pushswap_ab **ab)
{
	int	tmp;

	if ((*ab)->nb < 2)
		return ;
	tmp = (*ab)->b[0];
	(*ab)->b[0] = (*ab)->b[1];
	(*ab)->b[1] = tmp;
}

void	ft_pushswap_ss(t_pushswap_ab **ab)
{
	ft_pushswap_sa(ab);
	ft_pushswap_sb(ab);
}
