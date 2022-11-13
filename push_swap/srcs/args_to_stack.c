/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 07:51:42 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/23 13:30:51 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../libs/push_swap.h"
#include <stdlib.h>

static	void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	tab_size(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	args_isdigit(char *joined)
{
	int	i;

	i = 0;
	while (joined[i])
	{
		if (!((joined[i] >= '0' && joined[i] <= '9')
				|| joined[i] == ' ' || joined[i] == '-'))
			return (0);
		if (joined[i] == '-' && (!(joined[i + 1] >= '0'
					&& joined[i + 1] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

char	*join_args(char **args)
{
	char	*joined;
	char	*tmp;
	int		i;

	i = 2;
	joined = ft_strjoin(args[1], " ");
	if (!joined)
		return (NULL);
	while (args[i])
	{
		tmp = ft_strjoin(joined, args[i++]);
		free(joined);
		joined = tmp;
	}
	return (joined);
}

int	args_to_stack(char **args, int ac, t_stack **stack)
{
	char	*joined;
	char	**splitted;
	int		i;

	(void) ac;
	joined = join_args(args);
	if (!(args_isdigit(joined)))
		return (free(joined), 0);
	splitted = ft_split(joined, ' ');
	free(joined);
	i = tab_size(splitted) - 1;
	while (i >= 0)
	{
		if (!(check_int_overflow(splitted[i])))
		{
			ft_free(splitted);
			if (*stack)
				clear_stack(stack);
			return (0);
		}
		add_node(stack, new_node(ft_atoi(splitted[i--]), 0));
	}
	ft_free(splitted);
	return (1);
}
