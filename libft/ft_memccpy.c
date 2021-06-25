/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:10:14 by pnielly           #+#    #+#             */
/*   Updated: 2021/04/18 20:38:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	unsigned char		*d1;
	unsigned const char	*s1;

	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if (!(n))
		return (NULL);
	while (n-- > 0 && *s1 != (unsigned char)c)
		*d1++ = *s1++;
	if (*s1 != (unsigned char)c)
		return (NULL);
	else
		*d1++ = *s1++;
	return (d1);
}
