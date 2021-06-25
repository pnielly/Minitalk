/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:01:45 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 20:56:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

/**
** Here we'll send each byte bit by bit.
** If the bit = 0 we'll send a SIGUSR1
** If the bit = 1 we'll send a SIGUSR2
**/

void	send_byte(int pid, unsigned char byte)
{
	u_int8_t	position;

	position = 1 << 6;
	while (position)
	{
		if (!(byte & position))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Send byte failed, possibly wrong pid");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Send byte failed, possibly wrong pid");
		}
		position >>= 1;
		usleep(600);
	}
}

/**
** pid is the pid of the server to communicate with.
** msg is the message to send.
** Here we send the message byte by byte to send_byte()
**/

void	ft_send(int pid, char *msg)
{
	while (*msg)
	{
		send_byte(pid, *msg);
		msg++;
	}
	send_byte(pid, *msg);
}

void	ft_success(pid_t sig)
{
	ft_putstr("Data has been received. sig = ");
	ft_putnbr((int)sig);
	ft_putstr_endl(".");
}

int	usage(void)
{
	ft_putstr_endl("usage : ./client <server_pid> <your message>");
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction sa_success;

	if (ac != 3)
		return (usage());
	sa_success.sa_handler = ft_success;
	if (sigaction(SIGUSR1, &sa_success, NULL) != 0)
		ft_error("Signal error on the client side.");
	ft_send(ft_atoi(av[1]), av[2]);
	return (0);
}
