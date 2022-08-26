/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:30:58 by mahernan          #+#    #+#             */
/*   Updated: 2022/05/06 11:36:41 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (j + i) < len)
		{
			if (haystack[j + i] == '\0' && needle[i] == '\0')
				return ((char *)&haystack[j]);
			++i;
		}
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		j++;
	}
	return (0);
}
