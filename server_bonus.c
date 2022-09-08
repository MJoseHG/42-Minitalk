/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:59:21 by mahernan          #+#    #+#             */
/*   Updated: 2022/09/05 12:59:25 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>

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

static void	ft_receive_byte(int sign, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	byte = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sign == SIGUSR2)
		byte = byte | 1;
	if (++i == 8)
	{
		i = 0;
		if (byte == '\0')
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(byte, 1);
		byte = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		byte <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_color_fd(ANSI_COLOR_GREEN, "PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = ft_receive_byte;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
