/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:57:14 by dakim             #+#    #+#             */
/*   Updated: 2020/04/12 11:57:32 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_delimiter_counter(char const *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 1;
	while (*(s + (++i)))
		if (*(s + i) == c)
			++count;
	return (count);
}

static int	ft_before_delimiter_len(char const *s, char c)
{
	int count;

	count = -1;
	while (*(s + (++count)))
		if (*(s + count) == c)
			break ;
	return (count);
}

static char	*ft_before_delimiter_str(char const *s, char c)
{
	char	*return_str;
	int		i;
	int		len;

	i = -1;
	len = ft_before_delimiter_len(s, c);
	return_str = NULL;
	if ((return_str = ft_calloc(sizeof(char), len + 1)))
	{
		while (*(s + (++i)) && i < len)
		{
			if (*(s + i) == c)
				break ;
			*(return_str + i) = *(s + i);
		}
	}
	return (return_str);
}

void		*ft_free_split(char **str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		free((*(str + i) + 0));
		++i;
	}
	free(str);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		row;

	i = 0;
	row = 0;
	if (!s)
		return (NULL);
	if ((result = malloc(sizeof(char *) * (ft_delimiter_counter(s, c) + 1))))
	{
		while (*(s + i))
		{
			if (*(s + i) == c)
				++i;
			else
			{
				if ((*(result + row++) = ft_before_delimiter_str((s + i), c)))
					i += ft_before_delimiter_len((s + i), c);
				else
					return (ft_free_split(result));
			}
		}
		*(result + row) = NULL;
	}
	return (result);
}
