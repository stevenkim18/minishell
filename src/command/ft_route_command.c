/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:05:05 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 16:22:45 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_test(const char *str, int *index)
{
	if (*str)
	{
		while (*(str + *index)
		&& *(str + *index) != ';' && *(str + *index) != '|')
		{
			write(STDOUT, (str + *index), 1);
			++(*index);
		}
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	}
	return (ENOCMD);
}

int			ft_check_echo_pwd(const char *str, int *index, int i)
{
	if (ft_strnstr(str + i, ECHO_STR, ft_strlen(ECHO_STR))
	|| ft_strnstr(str + i, ECHO_D, ft_strlen(ECHO_D))
	|| ft_strnstr(str + i, ECHO_S, ft_strlen(ECHO_S)))
	{// TODO *(str + *index) == '|'인경우 파이프에서 데이터 빼내기
		*index = i;
		ft_trim_command(str, index, ECHO_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	else if (ft_strnstr(str + i, PWD_STR, ft_strlen(PWD_STR))
	|| ft_strnstr(str + i, PWD_D, ft_strlen(PWD_D))
	|| ft_strnstr(str + i, PWD_S, ft_strlen(PWD_S)))
	{
		ft_flush_pipe(str + *index);
		*index = i;
		ft_trim_command(str, index, PWD_STR);
		ft_exec_process(ft_handle_pwd, str, index);
		return (0);
	}
	return (1);
}

int			ft_check_exit(const char *str, int *index, int i)
{
	if (ft_strnstr(str + i, EXIT_STR, ft_strlen(EXIT_STR))
	|| ft_strnstr(str + i, EXIT_D, ft_strlen(EXIT_D))
	|| ft_strnstr(str + i, EXIT_S, ft_strlen(EXIT_S)))
	{
		if (ft_suppress_command(str + *index))
		{
			ft_flush_pipe(str + *index);
			++(*index);
			ft_return_end(str, index);
			if (*(str + *index) == '|')
				ft_send_str(EMPTY_STR, ft_get_data_pipe());
			ft_set_index(*index);
			return (0);
		}
		else
		{
			char		command[1024];

			*index = i;
			ft_trim_command(str, index, EXIT_STR);
			ft_get_command(str + *index, command);
			if (ft_check_num(command) || 20 <= ft_strlen(command))
			{
				ft_putstr_fd(EXIT_STR, STDOUT);
				ft_putstr_fd(NEWLINE_STR, STDOUT);
				ft_join_command("exit: ", command);
				ft_handle_error(ENONUMARG, command);
				exit(ENONUMARG);
			}
			else
			{
				int			exit_code;

				exit_code = ft_atoi(command);
				printf("exit = %d\n", exit_code);
				exit(exit_code);
			}
		}

		// 1. 첫 번 째 인자 받아옴
		// 2. 첫 번 째 인자가 숫자인경우
			// 2-1. 이후 인자가 오는지 파악
		// 3. 첫번째 인자가 문자인경우

		// 0인경우 성공 1 ~ 255 인경우 오류코드
		// 문자인경우 255
		// 인자가 많은경우 1
		// 첫번 째 인자가 숫자인경우 => 인자가 많음으로 처리
		// TODO 뒤의 인자가 숫자가 아닌경우 "bash: exit: dfsf: numeric argument required" 출력 및 종료 / 에러코드 = 255
		// TODO 뒤의 인자가 한개 이상인경우 "bash: exit: too many arguments" 출력 및 종료 / 에러코드 = 1
		// TODO 합쳐진경우 체크 필요
	}
	return (1);
}

int			ft_check_cd(const char *str, int *index, int i)
{
	if (ft_strnstr(str + i, CD_STR, ft_strlen(CD_STR))
	|| ft_strnstr(str + i, CD_D, ft_strlen(CD_D))
	|| ft_strnstr(str + i, CD_S, ft_strlen(CD_S)))
	{
		ft_flush_pipe(str + *index);
		if (ft_suppress_command(str + *index))
		{
			++(*index);
			ft_return_end(str, index);
			if (*(str + *index) == '|')
				ft_send_str(EMPTY_STR, ft_get_data_pipe());
		}
		else
		{
			*index = i;
			ft_trim_command(str, index, CD_STR);
			ft_handle_cd(str, index);
		}
		ft_set_index(*index);
		return (0);
	}
	return (1);
}

int			ft_check_export_env(const char *str, int *index, int i)
{
	if (ft_strnstr(str + i, EXPORT_STR, ft_strlen(EXPORT_STR))
	|| ft_strnstr(str + i, EXPORT_D, ft_strlen(EXPORT_D))
	|| ft_strnstr(str + i, EXPORT_S, ft_strlen(EXPORT_S)))
	{
		// TODO *(str + *index) == '|'인경우 파이프에서 데이터 빼내기
		*index = i;
		ft_trim_command(str, index, EXPORT_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	else if (ft_strnstr(str + i, ENV_STR, ft_strlen(ENV_STR))
	|| ft_strnstr(str + i, ENV_D, ft_strlen(ENV_D))
	|| ft_strnstr(str + i, ENV_S, ft_strlen(ENV_S)))
	{
		// TODO *(str + *index) == '|'인경우 파이프에서 데이터 빼내기
		*index = i;
		ft_trim_command(str, index, ENV_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	return (1);
}

int			ft_check_unset(const char *str, int *index, int i)
{
	if (ft_strnstr(str + i, UNSET_STR, ft_strlen(UNSET_STR))
	|| ft_strnstr(str + i, UNSET_D, ft_strlen(UNSET_D))
	|| ft_strnstr(str + i, UNSET_S, ft_strlen(UNSET_S)))
	{// TODO *(str + *index) == '|'인경우 파이프에서 데이터 빼내기
		*index = i;
		ft_trim_command(str, index, UNSET_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	return (1);
}

void		ft_route_command(const char *str, int *index)
{
	int			i;

	i = 0;
	if (str)
	{
		i = ft_get_str_location(str, index);
		if (!ft_check_echo_pwd(str, index, i))
			return ;
		else if (!ft_check_cd(str, index, i))
			return ;
		else if (!ft_check_exit(str, index, i))
			return ;
		else if (!ft_check_export_env(str, index, i))
			return ;
		else if (!ft_check_unset(str, index, i))
			return ;
		else
		{
			if (ft_check_last_command(str + *index))
				ft_set_index(++(*index));
			else
				ft_exec_process(ft_handle_built_in, str, index); // TODO "| grep 1" 처리 로직 생성 // TODO "| grep 1"인경우 무한반복 걸림
		}
	}
	else
		ft_handle_error(ENOMEM, NULL);
}
