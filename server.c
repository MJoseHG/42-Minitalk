/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:10:46 by mahernan          #+#    #+#             */
/*   Updated: 2022/08/10 11:10:50 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

void	ft_putstr_color_fd(char *color, char *s, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);
}

static void	ft_receive_message(int sign)
{
	static int				i = 0;
	static unsigned char	byte = 0;
	int						check;

	check = 0;
	if (sign == SIGUSR2)
		check = 1;
	byte = byte | check;
	if (++i == 8)
	{
		i = 0;
		write(1, &byte, 1);
		byte = 0;
	}
	else
		byte <<= 1;
}

int	main(void)
{
	ft_putstr_color_fd(ANSI_COLOR_GREEN, "PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, &ft_receive_message);
	signal(SIGUSR2, &ft_receive_message);
	while (1)
		pause();
	return (0);
}
