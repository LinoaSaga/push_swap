/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:00:50 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/19 17:03:55 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* write a message in the fd, free ab and return 0*/
int	ft_pushswap_return(char *s, int fd, t_pushswap_ab *ab, char *line)
{
	ft_putstr_fd(s, fd);
	if (ab)
	{
		free(ab->a);
		free(ab->b);
		free(ab);
	}
	if (line)
		free(line);
	return (0);
}

/*remove the \n at end of line if theres is one*/
/* return NULL in case of malloc and free correctly*/
char	*ft_pushswap_rmvn(char *s)
{
	size_t	k;
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	res = malloc((size + 1) * sizeof(char));
	if (!res)
	{
		free(s);
		return (NULL);
	}
	k = -1;
	while (++k < size)
		res[k] = s[k];
	res[k] = '\0';
	free(s);
	return (res);
}

/* convert a command into a number to use in the function*/
/* return -1 in case of invalid command*/
int	ft_pushswap_linetomove(char *line)
{
	if (ft_strncmp(line, "sa", ft_strlen(line)) == 0)
		return (0);
	else if (ft_strncmp(line, "sb", ft_strlen(line)) == 0)
		return (1);
	else if (ft_strncmp(line, "ss", ft_strlen(line)) == 0)
		return (2);
	else if (ft_strncmp(line, "pa", ft_strlen(line)) == 0)
		return (3);
	else if (ft_strncmp(line, "pb", ft_strlen(line)) == 0)
		return (4);
	else if (ft_strncmp(line, "ra", ft_strlen(line)) == 0)
		return (5);
	else if (ft_strncmp(line, "rb", ft_strlen(line)) == 0)
		return (6);
	else if (ft_strncmp(line, "rr", ft_strlen(line)) == 0)
		return (7);
	else if (ft_strncmp(line, "rra", ft_strlen(line)) == 0)
		return (8);
	else if (ft_strncmp(line, "rrb", ft_strlen(line)) == 0)
		return (9);
	else if (ft_strncmp(line, "rrr", ft_strlen(line)) == 0)
		return (10);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	t_pushswap_ab	*ab;
	char			*line;

	if (argc < 2)
		return (0);
	ab = ft_pushswap_getinputs(argc, argv);
	if (!ab)
		return (ft_pushswap_return("Error\n", 2, NULL, NULL));
	line = get_next_line(0);
	while (line)
	{
		line = ft_pushswap_rmvn(line);
		if (ft_pushswap_linetomove(line) == -1)
		{
			return (ft_pushswap_return("Error\n", 2, ab, line));
		}
		ft_pushswap_domove(ft_pushswap_linetomove(line), &ab);
		free(line);
		line = get_next_line(0);
	}
	if (ft_pushswap_isnotsorted(ab))
		return (ft_pushswap_return("KO\n", 1, ab, line));
	return (ft_pushswap_return("OK\n", 1, ab, line));
}
