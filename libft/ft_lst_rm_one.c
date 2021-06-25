/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rm_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:23:27 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 20:44:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** removes the element located at the 'position' from a.
*/
void	ft_lst_rm_one(t_list **a, int position)
{
	t_list	*tmp;
	t_list	*deb;

	if (position == 1)
		*a = (*a)->next;
	else
	{
		deb = *a;
		position--;
		while (--position)
			*a = (*a)->next;
		tmp = *a;
		tmp = tmp->next;
		(*a)->next = (*a)->next->next;
		tmp->next = NULL;
		free(tmp);
		*a = deb;
	}
}
