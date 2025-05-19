/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:10:49 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 11:57:39 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* function like atoi and stock result in n*/
/* return 1 if it went well, 0 in case of error*/
/* error if num too big, or non num except first -*/
static char	ft_pushswap_readnum(char *str, int *n)
{
	long	num;
	long	sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = 44 - str[i];
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48) * sign;
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	*n = (int) num;
	return (1);
}

/* return 1 if there s no dup 0 otherwise*/
static char	ft_pushswap_nodup(int n, int *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
		{
			if (a[i] == a[j])
				return (0);
		}
	}
	return (1);
}

/* Subfunction to create and fill a*/
static int	*ft_pushswap_geta(int argc, char **argv)
{
	int		*a;
	int		k;

	a = malloc((argc - 1) * sizeof(int));
	if (!a)
		return (NULL);
	k = 0;
	while (++k < argc)
	{
		if (!ft_pushswap_readnum(argv[k], &a[k - 1]))
		{
			free(a);
			return (NULL);
		}
	}
	if (!ft_pushswap_nodup(argc - 1, a))
	{
		free(a);
		return (NULL);
	}
	return (a);
}

/* Main function to get the inputs*/
/* Return NULL in case of malloc problem or if*/
/* an input was incorrect or in case of double*/
t_pushswap_ab	*ft_pushswap_getinputs(int argc, char **argv)
{
	t_pushswap_ab	*res;

	res = malloc(sizeof(t_pushswap_ab));
	if (!res)
		return (NULL);
	res->na = argc - 1;
	res->nb = 0;
	res->a = ft_pushswap_geta(argc, argv);
	if (!res->a)
	{
		free (res);
		return (NULL);
	}
	res->b = malloc(res->na * sizeof(int));
	if (!res->b)
	{
		free (res->a);
		free (res);
		return (NULL);
	}
	return (res);
}
