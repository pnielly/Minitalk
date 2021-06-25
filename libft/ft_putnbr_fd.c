/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:27:18 by pnielly           #+#    #+#             */
/*   Updated: 2021/06/25 15:39:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display(int n, int fd)
{
	if (n / 10 != 0)
		display(n / 10, fd);
	ft_putchar_fd('0' - (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	else
		n = -n;
	display(n, fd);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
