/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:04:27 by dakim             #+#    #+#             */
/*   Updated: 2020/08/15 17:37:16 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(void)
{
	ft_pipe_init();
	// ft_handle_command();

	// 파이프 재사용 테스트
	// ft_send_signal(123);
	// printf("%d\n", ft_get_signal());
	// ft_send_signal(123);
	// printf("%d\n", ft_get_signal());
	// ft_send_signal(123);
	// printf("%d\n", ft_get_signal());

	// 프로세스 재사용 테스트
	// int signal;
	// pid_t pid;
	// signal = ft_start_process(&pid);
	// ft_handle_error(signal, NULL);
	// if (pid == 0)
	// {
	// 	ft_end_process(127);
	// }
	// signal = ft_start_process(&pid);
	// ft_handle_error(signal, NULL);
	// if (pid == 0)
	// {
	// 	ft_end_process(0);
	// }
	// signal = ft_start_process(&pid);
	// ft_handle_error(signal, NULL);
	// if (pid == 0)
	// {
	// 	ft_end_process(ENOMEM);
	// }



	return (0);
}
