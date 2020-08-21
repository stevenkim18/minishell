/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:01:01 by dakim             #+#    #+#             */
/*   Updated: 2020/08/21 17:41:52 by dakim            ###   ########.fr       */
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

void		ft_check_home_dir(char *command)
{
	if (*command == '~')
	{
		if (*(command + 1) == '/')
		{


		}
		else
		{

		}
	}
}

extern char **environ;

int main()
{
	int i;
	i = -1;
	while (*(environ + ++i))
	{
		printf("%s\n", *(environ + i));
	}
  return 0;
}
/*
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
		printf("4. file = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("4. %s\n", strerror(errno));
	// 3. 프로그램
	command = "/bin/ls";
	if (!stat(command, &buf))
		printf("5. program = %d\n", S_ISDIR(buf.st_mode));
	else
		printf("5. %s\n", strerror(errno));
	command = "./minishell";
	if (!stat(command, &buf))
		printf("5. program = %d\n", S_ISDIR(buf.st_mode));
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
*/
