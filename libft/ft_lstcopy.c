/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:05:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 22:30:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcopy(t_list **a, t_list **b)
{
	t_list	*c;
	t_list	*d;

	*b = ft_lstnew((*a)->content);
	c = *b;
	d = *a;
	*a = (*a)->next;
	while (*a)
	{
		c->next = ft_lstnew((*a)->content);
		*a = (*a)->next;
		c = c->next;
	}
	*a = d;
}
