/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:01:45 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 15:45:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
	(void)sig;
	ft_putstr(YELLOW);
	ft_putstr_endl("Data has been received.");
}

void	ft_works(pid_t sig)
{
	(void)sig;
	usleep(1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa_success;
	struct sigaction	sa_works;

	if (ac != 3)
		return (usage());
	ft_bzero(&sa_success, sizeof(sa_success));
	ft_bzero(&sa_works, sizeof(sa_works));
	sa_success.sa_handler = ft_success;
	sa_works.sa_handler = ft_works;
	if (sigaction(SIGUSR2, &sa_success, NULL) != 0)
		ft_error("Signal SIGUSR2 error on the client side.");
	if (sigaction(SIGUSR1, &sa_works, NULL) != 0)
		ft_error("Signal SIGUSR1 error on the client side.");
	ft_send(ft_atoi(av[1]), av[2]);
	return (0);
}
