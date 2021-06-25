/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:30:51 by pnielly           #+#    #+#             */
/*   Updated: 2021/04/18 20:36:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	while (*s1 && ft_set(*s1, set))
		s1++;
	i = 0;
	while (s1[i])
		i++;
	i--;
	while (ft_set(s1[i], set) && i > -1)
		i--;
	dest = malloc(sizeof(*s1) * (i + 2));
	if (!dest)
		return (0);
	j = -1;
	while (++j <= i)
		dest[j] = s1[j];
	dest[j] = '\0';
	return (dest);
}
