/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:14:47 by pnielly           #+#    #+#             */
/*   Updated: 2021/04/18 20:27:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;
	unsigned int		i;
	unsigned int		j;

	sa = s1;
	sb = s2;
	i = 0;
	j = 0;
	if (!n)
		return (0);
	while (i < n)
	{
		j = sa[i] - sb[i];
		if (j != 0)
			return (j);
		i++;
	}
	return (j);
}
