/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:14:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/04 11:35:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define BUFFER_SIZE 1024

/**
** bit is the bit's position
** byte is the char position
** message is the message to write
** buff_overflow tells if the message is > than BUFFER_SIZE
** done tells if the whole message is received.
**/

typedef struct s_msg
{
	size_t	bit;
	size_t	byte;
	char	message[BUFFER_SIZE];
	int		buff_overflow;	
	int		done;
}		t_msg;

void	ft_error(char *s);
void	ft_putnbr(int nb);
void	*ft_bzero(void *s, size_t n);
void	ft_putstr(char *s);
void	ft_putstr_endl(char *s);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);

#endif
