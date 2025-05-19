/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:12:10 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 11:49:15 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

/* libprintf.a*/
int					ft_printf(const char *s, ...);
void				ft_putstr_fd(char *s, int fd);

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
void				ft_pushswap_printmove(char move);
void				ft_pushswap_domove(char move, t_pushswap_ab **ab);
void				ft_pushswap_sa(t_pushswap_ab **ab);
void				ft_pushswap_sb(t_pushswap_ab **ab);
void				ft_pushswap_ss(t_pushswap_ab **ab);
/* ft_pushswap_move2.c*/
void				ft_pushswap_pa(t_pushswap_ab **ab);
void				ft_pushswap_pb(t_pushswap_ab **ab);
void				ft_pushswap_ra(t_pushswap_ab **ab);
void				ft_pushswap_rb(t_pushswap_ab **ab);
void				ft_pushswap_rr(t_pushswap_ab **ab);
/* ft_pushswap_move3.c*/
void				ft_pushswap_rra(t_pushswap_ab **ab);
void				ft_pushswap_rrb(t_pushswap_ab **ab);
void				ft_pushswap_rrr(t_pushswap_ab **ab);

/* ft_pushswap_algo.c*/
char				ft_pushswap_sort3(t_pushswap_ab *ab, char *state);
char				ft_pushswap_calcmove(t_pushswap_ab *ab, char *state);
/* ft_pushswap_algon5.c*/
char				ft_pushswap_sort5(t_pushswap_ab *ab, char *state);
/* ft_pushswap_algo_utils.c*/
char				ft_pushswap_isnotsorted(t_pushswap_ab *ab);
size_t				ft_pushswap_idealpos(int *x, size_t size, int n);
char				ft_pushswap_sortturk(t_pushswap_ab *ab, char *state);
char				ft_pushswap_islowestfirst(t_pushswap_ab *ab);
size_t				ft_pushswap_lowestpos(int *x, size_t size);
size_t				ft_pushswap_highestpos(int *x, size_t size);
/* ft_pushswap_algoturk.c*/
t_pushswap_nmove	ft_pushswap_sortturk_evalop(t_pushswap_ab *ab, size_t k);
char				ft_pushswap_sortturk_p2(t_pushswap_ab *ab, char *state);
char				ft_pushswap_sortturk_p4(t_pushswap_ab *ab, char *state);
char				ft_pushswap_sortturk_p5(t_pushswap_ab *ab, char *state);
char				ft_pushswap_sortturk(t_pushswap_ab *ab, char *state);
/* ft_pushswap_algoturk_p2.c*/
void				ft_pushswap_sortturk_evalop_kb(t_pushswap_ab *ab,
						t_pushswap_nmove *nm);
void				ft_pushswap_sortturk_evalop_ud(t_pushswap_ab *ab,
						t_pushswap_nmove *nm);
void				ft_pushswap_sortturk_evalop_du(t_pushswap_ab *ab,
						t_pushswap_nmove *nm);
void				ft_pushswap_sortturk_evalop_uu(t_pushswap_ab *ab,
						t_pushswap_nmove *nm);
void				ft_pushswap_sortturk_evalop_dd(t_pushswap_ab *ab,
						t_pushswap_nmove *nm);
/* ft_pushswap_algoturk_p4.c*/
size_t				ft_pushswap_sortturk_p4core(t_pushswap_ab *ab);

#endif