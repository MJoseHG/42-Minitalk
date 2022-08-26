/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:05:42 by mahernan          #+#    #+#             */
/*   Updated: 2022/05/06 11:24:18 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pnt;

	pnt = b;
	while (len > 0)
	{
		*pnt = (unsigned char)c;
		pnt++;
		len--;
	}
	return (b);
}
