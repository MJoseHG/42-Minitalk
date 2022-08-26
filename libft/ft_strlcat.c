/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:38:55 by mahernan          #+#    #+#             */
/*   Updated: 2022/05/06 11:36:12 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	result;
	int		i;

	len_dst = 0;
	len_src = 0;
	i = 0;
	while (dst[len_dst])
		len_dst++;
	while (src[len_src])
		len_src++;
	if (dstsize > len_dst)
		result = len_dst + len_src;
	else
		result = len_src + dstsize;
	while (src[i] && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (result);
}
