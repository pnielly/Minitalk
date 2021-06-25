/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:42:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 15:46:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *a, t_list *b)
{
	char	*tmp;

	if (!a || !b)
	{
		ft_putstr_endl("ERROR : a or b is empty !");
		return ;
	}
	tmp = b->content;
	b->content = a->content;
	a->content = tmp;
	return ;
}
