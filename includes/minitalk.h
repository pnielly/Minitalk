/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:14:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/05 15:40:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define BUFFER_SIZE 10240

/**
** Colors
**/

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NC "\033[0;37m"

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
int		usage(void);

#endif
