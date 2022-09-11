/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:10:57 by mahernan          #+#    #+#             */
/*   Updated: 2022/08/10 11:11:00 by mahernan         ###   ########.fr       */
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

static void	ft_send_message(int pid, char *msg)
{
	int		i;
	char	bit;

	while (*msg)
	{
		i = 8;
		bit = *msg;
		while (i--)
		{
			if (bit >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		msg++;
	}
}

void	ft_error_client(int pid, char *msg)
{
	if (!pid || !*msg)
	{
		ft_putstr_color_fd(ANSI_COLOR_RED, "Client: Unexpected error.\n", 2);
		ft_putstr_color_fd(ANSI_COLOR_YELLOW, "Null PID or NULL Message\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
	{
		ft_putstr_color_fd(ANSI_COLOR_RED, "Client: Unexpected error.\n", 2);
		ft_putstr_color_fd(ANSI_COLOR_YELLOW, "Wrong PID\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr_color_fd(ANSI_COLOR_RED, "Client: Invalid arguments.\n", 2);
		ft_putstr_color_fd(ANSI_COLOR_YELLOW,
			"Correct format: [./client <PID> <STR>].\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	ft_error_client(pid, msg);
	ft_send_message(pid, msg);
	return (0);
}
