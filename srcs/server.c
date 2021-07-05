/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:32:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 16:04:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_msg	g_msg;

/*
** Note : kill(info->si_pid, SIGUSR1) is here to make the program sleep
** This prevents the program to freeze if the message is too long (> ~200)
** Tried to simply replace it with a usleep(1), but didn't work.
*/

void	ft_onebit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	kill(info->si_pid, SIGUSR1);
	if (!g_msg.bit)
	{
		g_msg.bit = 1 << 6;
		(g_msg.byte)++;
	}
	g_msg.message[g_msg.byte] += g_msg.bit;
	g_msg.bit >>= 1;
	if (g_msg.byte == BUFFER_SIZE - 2 && !g_msg.bit)
		g_msg.buff_overflow = 1;
}

void	ft_nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_msg.bit)
	{
		g_msg.bit = 1 << 6;
		(g_msg.byte)++;
	}
	g_msg.bit >>= 1;
	if (g_msg.byte == BUFFER_SIZE - 2 && !g_msg.bit)
		g_msg.buff_overflow = 1;
	else if (!g_msg.message[g_msg.byte] && !g_msg.bit)
	{
		g_msg.done = 1;
		kill(info->si_pid, SIGUSR2);
	}
}

void	print_message(void)
{
	pause();
	if (g_msg.buff_overflow || g_msg.done)
	{
		ft_putstr(g_msg.message);
		ft_bzero(g_msg.message, BUFFER_SIZE);
		g_msg.byte = 0;
		g_msg.bit = 1 << 6;
		if (g_msg.done)
			ft_putstr_endl("");
		g_msg.buff_overflow = 0;
		g_msg.done = 0;
	}
}

void	welcome(int pid)
{
	ft_putstr(BLUE);
	ft_putstr_endl("Welcome to my Minitalk.");
	ft_putstr("Share this pid with your client(s): <");
	ft_putnbr(pid);
	ft_putstr_endl(">.");
	ft_putstr(WHITE);
}

int	main(void)
{
	struct sigaction	sa_null;
	struct sigaction	sa_one;

	g_msg.buff_overflow = 0;
	g_msg.done = 0;
	g_msg.byte = 0;
	g_msg.bit = 1 << 6;
	ft_bzero(g_msg.message, BUFFER_SIZE);
	welcome(getpid());
	ft_bzero(&sa_null, sizeof(sa_null));
	ft_bzero(&sa_one, sizeof(sa_one));
	sa_null.sa_flags = SA_SIGINFO;
	sa_one.sa_flags = SA_SIGINFO;
	sa_null.sa_sigaction = ft_nullbit;
	sa_one.sa_sigaction = ft_onebit;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa_null, NULL) != 0)
			ft_error("Signal error : SIGUSR1 on the server side.");
		if (sigaction(SIGUSR2, &sa_one, NULL) != 0)
			ft_error("Signal error : SIGUSR2 on the server side.");
		print_message();
	}
	return (0);
}
