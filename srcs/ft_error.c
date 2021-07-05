/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:10:32 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 15:47:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error(char *s)
{
	ft_putstr_endl(s);
	exit(1);
}

int	usage(void)
{
	ft_putstr(CYAN);
	ft_putstr("usage :");
	ft_putstr(BLUE);
	ft_putstr(" ./client");
	ft_putstr(WHITE);
	ft_putstr(" <server_pid>");
	ft_putstr(RED);
	ft_putstr_endl(" <your message>");
	return (0);
}
