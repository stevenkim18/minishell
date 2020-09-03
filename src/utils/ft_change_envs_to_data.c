/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_envs_to_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 02:43:09 by seunkim           #+#    #+#             */
/*   Updated: 2020/09/01 01:16:35 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void        ft_change_return_code(char (*tmp)[1024], int *i, int *j)
{
    char    *error_code;
    int     idx;

    error_code = ft_itoa(ft_handle_error(NO_ERROR, NULL));
    idx = 0;
    while (error_code[idx])
        (*tmp)[(*j)++] = error_code[idx++];
    *i += (idx + 1);
}

void        ft_change_env(const char *str, char (*tmp)[1024], int *i, int *j)
{
    char    key[1024];
    char    value[1024];
    int     x;
    
    x = 0;
    (*i)++;
    while (str[(*i)] != ' ' && str[*i] != 0 && str[*i] != '$')
        key[x++] = str[(*i)++];
    key[x] = 0;
    ft_get_env(key, value);
    x = 0;
    while (value[x])
        (*tmp)[(*j)++] = value[x++];
}

// 문자열에 환경변수나($HOME) error 코드($?)가 들어왔을 떄 처리
char        *ft_change_envs_to_data(const char *str)
{
    int     i;
    int     j;
    char    tmp[1024];

    i = 0;
    j = 0;
    while (str[i])
    {   
        if (str[i] == '$')
        {
            if (str[i + 1] == '?')
                ft_change_return_code(&tmp, &i, &j);
            else if (ft_isalnum(str[i + 1]) || str[i + i] == '_')
                ft_change_env(str, &tmp, &i, &j);
            else
               tmp[j++] = str[i++];
        }
        else
            tmp[j++] = str[i++];
    }
    tmp[j] = 0;
    return (ft_strdup(tmp));
}
