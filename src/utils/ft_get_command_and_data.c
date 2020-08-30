/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_and_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 03:03:03 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/31 02:52:50 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_strndup(char const *s, int n)
{
	int		idx;
	char	*ptr;

	idx = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (idx < n)
	{
		ptr[idx] = s[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

void        ft_move_idx(char *str, int *idx, int *count)
{
    while (str[*idx] && str[*idx] == ' ')
        (*idx)++;
    while (str[*idx])
    {
        if (str[*idx] != ' ' && str[*idx] != '\'' 
            && str[*idx] != '\"' && str[*idx] != 0)
        {
            while (str[*idx] != ' ' && str[*idx] != '\'' 
                    && str[*idx] != '\"' && str[*idx] != 0)
                (*idx)++;
            (*count)++;
        }
        else if (str[*idx] == '\'' || str[*idx] == '\"')
        {   
            (*idx)++;
            while (str[*idx] != '\'' && str[*idx] != '\"')
                (*idx)++;
            (*idx)++;
            (*count)++;
        }
        else
            (*idx)++;
    }
}

int         ft_wordcount(char *str)
{
    int     idx;
    int     count;
    
    if(ft_strlen(str) == 0)
        return (1);
    idx = 0;
    count = 0;
    ft_move_idx(str, &idx, &count);
    return (count);
}

void        ft_cut_datas(char *new_str, char ***datas, int *idx, int *tmp)
{
    while (new_str[*idx])
    {
        if (new_str[*idx] == '\'' || new_str[*idx] == '\"')
        {
            *tmp = ++(*idx);
            while (new_str[*idx] != '\'' && new_str[*idx] != '\"')
                (*idx)++;
            *(*datas)++ = ft_strndup((new_str + *tmp), *idx - *tmp);
            (*idx)++;
        }
        else if (new_str[*idx] != '\'' && new_str[*idx] != '\"' && new_str[*idx] != ' ')
        {
            *tmp = *idx;
            while (new_str[*idx] != '\'' && new_str[*idx] != '\"' 
                    && new_str[*idx] != ' ' && new_str[*idx] != 0)
                (*idx)++;
            *(*datas)++ = ft_strndup((new_str + *tmp), *idx - *tmp); 
        }
        else if (new_str[*idx] == ' ')
            (*idx)++;
    }
    *(*datas) = NULL;
}

char        **ft_get_command_and_data(const char *str)
{
    char    *new_str;
    char    **datas;
    char    **ret_datas;
    int     idx;
    int     tmp;
    
    new_str = ft_change_envs_to_data(str);
    if (!(datas = (char**)malloc(sizeof(char*) * (ft_wordcount(new_str) + 1))))
        return (NULL);
    idx = 0;
    tmp = 0;
    ret_datas = datas;
    while (new_str[idx] && new_str[idx] == ' ')
        idx++;
    ft_cut_datas(new_str, &datas, &idx, &tmp);
    free(new_str);
    return (ret_datas);
}
