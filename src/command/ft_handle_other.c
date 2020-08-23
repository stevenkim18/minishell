/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:01:01 by dakim             #+#    #+#             */
/*   Updated: 2020/08/23 14:19:00 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 1. get command
** 2. check command kind
** 3. execute command
*/

void		ft_get_command(const char *str, char *command)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (*(str + i) == ' ')
		++i;
	if (*(str + i) != '\'' && *(str + i) != '\"')
		while (*(str + i) != ' ')
		{
			command[j] = *(str + i++);
			++j;
		}
	else if (*(str + i) == '\"' || *(str + i) == '\'')
	{
		while (*(str + i) == '\'' || *(str + i) == '\"')
			++i;
		while (*(str + i) != '\'' && *(str + i) != '\"')
		{
			command[j] = *(str + i++);
			++j;
		}
	}
	command[j] = 0;
}

static void	ft_add_home_dir(char *command)
{
	char	dir[1024];
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_get_env("HOME", dir);
	while (*(dir + i))
		++i;
	while (*(command + ++j))
		dir[i++] = command[j];
	dir[i] = 0;
	i = -1;
	j = 0;
	while (*(dir + ++i))
		command[j++] = dir[i];
	command[j] = 0;
}

static void	ft_remove_home_dir(char *command)
{
	char	dir[1024];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(command + ++i))
		dir[j++] = command[i];
	dir[j] = 0;
	j = -1;
	i = 0;
	while (*(dir + ++j))
		command[i++] = dir[j];
	command[i] = 0;
}

void		ft_check_home_dir(char *command)
{
	if (*command == '~')
	{
		if (*(command + 1) == '/')
			ft_add_home_dir(command);
		else
			ft_remove_home_dir(command);
	}
}



int		main()
{
	char *command = NULL;
	struct stat buf;

	// 1. 디렉토리
	command = "/bin";
	if (!stat(command, &buf))
		printf("1 directory = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("1. %s\n", strerror(errno));

	command = "./include";
	if (!stat(command, &buf))
		printf("2 directory = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("2. %s\n", strerror(errno));

	command = "/Users/dakim/Documents";
	if (!stat(command, &buf))
		printf("3 ~ directory = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("3. %s\n", strerror(errno));
	command = "~/Documents";
	// ft_check_home_dir(command);
	if (!stat(command, &buf))
		printf("3 ~ directory = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("3. %s\n", strerror(errno));
	command = "../ft_services";
	if (!stat(command, &buf))
		printf("3 ~ directory = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("3. %s\n", strerror(errno));
	command = "../ft_services/";
	if (!stat(command, &buf))
		printf("3 ~ directory = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("3. %s\n", strerror(errno));
	// 2. 파일
	command = "/Users/dakim/Documents/42/cursus/c1/get_next_line/get_next_line.h";
	if (!stat(command, &buf))
		printf("4. file = %d\n", S_ISREG(buf.st_mode));
	else
		printf("4. %s\n", strerror(errno));
	// 3. 프로그램
	command = "/bin/ls";
	if (!stat(command, &buf))
		printf("5. program = %d\n", S_ISREG(buf.st_mode));
	else
		printf("5. %s\n", strerror(errno));
	command = "./minishell";
	if (!stat(command, &buf))
		printf("5. program = %d\n", S_ISREG(buf.st_mode));
	else
		printf("5. %s\n", strerror(errno));
	// 4. 링크
	command = "ls";
	if (!lstat(command, &buf))
		printf("6. link = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("6. %s\n", strerror(errno));
	// 5. 존재하지 않음
	command = "afakjfslkfjaoifjawiofjwoifjwi";
	if (!stat(command,&buf))
		printf("7. not = %d\n", S_ISDIR(buf.st_mode));
	else
	{
		printf("7. %s\n", strerror(errno));
		// printf("%d\n", errno);
		// printf("%s\n", command);
		// ft_handle_error(errno, command);
	}
}
