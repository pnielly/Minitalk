/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:58:39 by pnielly           #+#    #+#             */
/*   Updated: 2021/05/10 11:26:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnum(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (i > 0 && ft_isdigit(s[i - 1]) && ft_strchr("-+", s[i]))
			return (0);
		else if (ft_strchr("-+", s[i]) && !ft_isdigit(s[i + 1]))
			return (0);
		else if (!ft_isdigit(s[i]) && !ft_strchr("-+", s[i])
			&& !ft_isdelim(s[i]))
			return (0);
	}
	return (1);
}

/*
** ft_issdigit() checks if c is a digit or 
** if c == '-' or c == '+' and next character is a digit
*/

int	ft_issdigit(int c, int next)
{
	if (ft_isdigit(c)
		|| (ft_isdigit(next) && ft_strchr("+-", c)))
		return (1);
	return (0);
}
