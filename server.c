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

#include <libft.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr_color_fd(char *color, char *s, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);
}

// char	*ft_straddc_first(char c)
// {
// 	char	*add;

// 	add = (char *)malloc(sizeof(char) * 2);
// 	if (!add)
// 		return (NULL);
// 	add[0] = c;
// 	add[1] = '\0';
// 	return (add);
// }

// char	*ft_straddc(char *str, char c)
// {
// 	char	*add;
// 	int		i;

// 	if (!c)
// 		return (NULL);
// 	if (!str)
// 		return (ft_straddc_first(c));
// 	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
// 	if (!add)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	i = -1;
// 	while (str[++i])
// 		add[i] = str[i];
// 	free(str);
// 	add[i++] = c;
// 	add[i] = '\0';
// 	return (add);
// }

// void	error_server(int pid, char *str)
// {
// 	if (str)
// 		free(str);
// 	ft_putstr_color_fd(ANSI_COLOR_RED,
// 		"Server: Unexpected error.\n", 2);
// 	kill(pid, SIGUSR2);
// 	exit(EXIT_FAILURE);
// }

// char	*print_string(char *message)
// {
// 	ft_putstr_fd(message, 1);
// 	free(message);
// 	return (NULL);
// }

// void	handler_sigusr(int signum, siginfo_t *info, void *context)
// {
// 	static char	c = 0xFF;
// 	static int	bits = 0;
// 	static int	pid = 0;
// 	static char	*message = 0;

// 	(void)context;
// 	if (info->si_pid)
// 		pid = info->si_pid;
// 	if (signum == SIGUSR1)
// 		c ^= 0x80 >> bits;
// 	else if (signum == SIGUSR2)
// 		c |= 0x80 >> bits;
// 	if (++bits == 8)
// 	{
// 		if (c)
// 			message = ft_straddc(message, c);
// 		else
// 			message = print_string(message);
// 		bits = 0;
// 		c = 0xFF;
// 	}
// 	if (kill(pid, SIGUSR1) == -1)
// 		error_server(pid, message);
// }

static void	receive_byte(int sign)
{
	static int				cnt;
	static unsigned char	byte;
	int						control;

	cnt = 0;
	byte = 0;
	control = 0;
	if (sign == SIGUSR2)
		control = 1;
	byte = byte | control;
	if (++cnt == 8)
	{
		cnt = 0;
		write(1, &byte, 1);
		// ft_putchar_fd(byte, 1);
		byte = 0;
	}
	else
		byte <<= 1;

}

int	main(void)
{
	ft_putstr_color_fd(ANSI_COLOR_GREEN,
		"PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, &receive_byte);
	signal(SIGUSR2, &receive_byte);
	while (1)
		pause();
	return (0);
}
