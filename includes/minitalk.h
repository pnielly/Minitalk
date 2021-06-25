/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:14:40 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 20:51:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINITALK_H__
# define __MINITALK_H__

# include "../libft/libft.h"
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
	int	buff_overflow;	
	int	done;
}		t_msg;

void	ft_error(char *s);

#endif
