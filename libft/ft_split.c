/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:00:56 by mahernan          #+#    #+#             */
/*   Updated: 2022/05/06 11:17:13 by mahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_string_counter(const char *s, char c)
{
	int		string;
	int		i;
	char	**array;

	i = 0;
	string = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			string++;
		i++;
	}
	array = (char **)malloc(sizeof(char *) * (string + 1));
	if (!array)
		return (NULL);
	return (array);
}

static void	ft_letter_counter(const char *s, char c, char **array)
{
	int		i;
	int		string;
	int		letter;

	i = 0;
	string = 0;
	letter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			letter++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			array[string] = malloc(sizeof(char) * (letter + 1));
			if (!(array[string]))
			{
				while (array[string])
					free(array[string--]);
			}
			string++;
			letter = 0;
		}
		i++;
	}
}

static void	ft_fill_array(char const *s, char c, char **array)
{
	int		i;
	int		string;
	int		letter;

	i = 0;
	string = 0;
	letter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			array[string][letter] = s[i];
			letter++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			array[string][letter] = '\0';
			string++;
			letter = 0;
		}
		i++;
	}
	array[string] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_string_counter(s, c);
	if (!array)
		return (NULL);
	ft_letter_counter(s, c, array);
	ft_fill_array(s, c, array);
	return (array);
}
