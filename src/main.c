/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 09:20:17 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_handle_gnl(char **line)
{
	write(1, "MINISHELL >>", 13);
	return (get_next_line(1, line));
}

static void		ft_handle_command(void)
{
	char		*command;
	int			read_result;

	command = NULL;
	read_result = INITIAL_INT;
	while ((read_result = ft_handle_gnl(&command)) > 0)
	{
		printf("%s\n", command);
		// 파싱
		// 명령어 실행
		free(command);
	}
	if (command)
	{
		// 명령어 처리 필요
		free(command);
	}
}

int main()
{
	ft_handle_command();
	return (0);
}
