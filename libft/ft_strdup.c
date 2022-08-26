/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:13:21 by mahernan          #+#    #+#             */
/*   Updated: 2022/04/27 15:37:30 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d1;
	size_t	s1_len;

	s1_len = ft_strlen(s1) + 1;
	d1 = malloc(s1_len);
	if (!d1)
		return (NULL);
	ft_strlcpy (d1, s1, s1_len);
	return (d1);
}
