/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:00:47 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 16:25:06 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdlib.h>

/* libprintf.a*/
int					ft_printf(const char *s, ...);
void				ft_putstr_fd(char *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);

/* gnl/get_next_line_bonus.c*/
char				*get_next_line(int fd);

/* nX = number of elements in stack X*/
/* stack coded as array of N*/
typedef struct s_pushswap_ab
{
	int		*a;
	int		*b;
	size_t	na;
	size_t	nb;
}	t_pushswap_ab;

/* struct to stock infos while optimal next move calculation*/
/* see algoturkp2 function */
/* calculate for an element in a, the element that should be first in b*/
/* the number of operations to push a correctly in b and the next_move to do*/
typedef struct s_pushswap_nmove
{
	size_t			ka;
	size_t			kb;
	char			n_move;
	unsigned int	nb_op;
}	t_pushswap_nmove;

/* ft_pushswap_inputs.c*/
t_pushswap_ab		*ft_pushswap_getinputs(int argc, char **argv);

/* ft_pushswap_move1.c*/
void				ft_pushswap_domove(char move, t_pushswap_ab **ab);
/* ft_pushswap_algo_utils.c*/
char				ft_pushswap_isnotsorted(t_pushswap_ab *ab);

#endif