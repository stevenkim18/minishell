/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 10:37:38 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_handle_gnl(char **line)
{
	ft_putstr_fd("MINISHELL >>", STDOUT);
	return (get_next_line(STDOUT, line));
}

static void		ft_handle_command(void)
{
	char		*command;
	char		*tmp_command;
	int			read_result;

	command = NULL;
	read_result = INITIAL_INT;
	while ((read_result = ft_handle_gnl(&command)) > 0)
	{
		tmp_command = command;
		if (!(command = ft_trim_str(command)))
			ft_end_process();
		printf("|%s|\n", command);
		free(tmp_command);
		// 파싱
		// 명령어 실행
		free(command);
	}
	if (command)
	{
		// 파싱
		// 명령어 실행
		// 함수 종료
		free(command);
	}
}

int main()
{
	ft_handle_command();
	return (0);
}
