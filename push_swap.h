/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:12:10 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/13 14:55:04 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

/* libprintf.a*/
int	ft_printf(const char *s, ...);
void	ft_putstr_fd(char *s, int fd);

/* nX = number of elements in stack X*/
/* stack coded as array of N*/
typedef struct s_pushswap_ab
{
	int	*a;
	int	*b;
	int	na;
	int	nb;
}	t_pushswap_ab;

/* ft_pushswap_inputs.c*/
t_pushswap_ab	*ft_pushswap_getinputs(int argc, char **argv);

#endif