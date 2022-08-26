/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:12:08 by mahernan          #+#    #+#             */
/*   Updated: 2022/04/27 16:52:37 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pnt;

	pnt = malloc(count * size);
	if (((count == SIZE_MAX) && count > 1) || ((size == SIZE_MAX) && size > 1))
		return (NULL);
	if (pnt == 0)
		return (pnt);
	if (!pnt)
		return (NULL);
	ft_bzero(pnt, count * size);
	return (pnt);
}
