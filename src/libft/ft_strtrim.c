/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:45:55 by dakim             #+#    #+#             */
/*   Updated: 2020/04/12 12:18:13 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_c(char *delimiter, char c)
{
	int i;

	i = -1;
	while (*(delimiter + (++i)))
	{
		if (*(delimiter + i) == c)
			return (1);
	}
	return (0);
}

static char		*ft_get_str(char const *s1, char const *set)
{
	int		flag;
	char	*return_str;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	if (!(return_str = ft_calloc(sizeof(char), ft_strlen((char*)s1) + 1)))
		return (NULL);
	i = -1;
	flag = 1;
	j = -1;
	while (++i < ft_strlen((char*)s1))
	{
		if (!ft_check_c((char*)set, (char)*(s1 + i)))
			flag = 0;
		if (!(flag && ft_check_c((char*)set, (char)*(s1 + i))))
			*(return_str + (++j)) = *(s1 + i);
	}
	return (return_str);
}

static char		*ft_copy_str(char *str)
{
	char	*return_str;
	int		i;

	if (!str)
		return (NULL);
	if (!(return_str = ft_calloc(sizeof(char), ft_strlen(str) + 1)))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(str))
		*(return_str + i) = *(str + i);
	free(str);
	return (return_str);
}

static char		*ft_trim_end(char *str, char const *set)
{
	int	len;
	int flag;

	if (!str || !set)
		return (NULL);
	len = ft_strlen(str);
	flag = 1;
	while (0 < --len)
	{
		if (!ft_check_c((char*)set, *(str + len)))
			flag = 0;
		if (flag && ft_check_c((char*)set, *(str + len)))
			*(str + len) = 0;
	}
	return (ft_copy_str(str));
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char *return_str;

	if (!s1 || !set)
		return (NULL);
	if (!(return_str = ft_get_str(s1, set)))
		return (NULL);
	return (ft_trim_end(return_str, set));
}
