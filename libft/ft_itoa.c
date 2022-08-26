/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:09:57 by mahernan          #+#    #+#             */
/*   Updated: 2022/05/04 12:44:12 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	ft_digit_n(long n_l, int sign)
{
	unsigned int	digit_n;

	if (n_l == 0)
		return (1);
	digit_n = 0;
	while (n_l > 0)
	{
		n_l /= 10;
		digit_n++;
	}
	if (sign == -1)
		digit_n++;
	return (digit_n);
}

static void	ft_convert_n(char *str, long n_l, unsigned int digit_n, int sign)
{
	str[digit_n] = '\0';
	str[--digit_n] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		str[--digit_n] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char			*str;
	long			n_l;
	unsigned int	digit_n;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		n_l = (long)n * -1;
		sign = -1;
	}
	else
		n_l = n;
	digit_n = ft_digit_n(n_l, sign);
	str = malloc(sizeof(char) * (digit_n + 1));
	if (!str)
		return (NULL);
	ft_convert_n(str, n_l, digit_n, sign);
	return (str);
}
