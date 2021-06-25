/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_duplicates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:53:15 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 18:22:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_has_duplicates(char *s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = i;
		while (s[++j])
		{
			if (s[i] == s[j])
				return (1);
		}
	}
	return (0);
}

int	ft_has_dup_tab(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = i;
		while (s[++j])
		{
			if (!ft_strcmp(s[i], s[j]))
				return (1);
		}
	}
	return (0);
}
