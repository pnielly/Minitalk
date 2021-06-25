/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:26:08 by pnielly           #+#    #+#             */
/*   Updated: 2021/04/18 20:42:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	j = start;
	i = 0;
	while (len-- > 0 && s[j] != 0)
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
