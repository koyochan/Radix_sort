/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:34 by kotkobay          #+#    #+#             */
/*   Updated: 2024/10/09 19:16:26 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_save(int fd, char *save)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr_c(save, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		save = ft_strjoin_c(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_c(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

// static void	validate_std(char *line)
// {
// 	int	i;
// 	int	argc;

// 	i = 0;
// 	argc = 2;
// 	printf("line:%s/\n", line);
// 	while (line[i])
// 	{
// 		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\r')
// 		{
// 			argc++;
// 		}
// 		printf("argc: %d %d\n", argc, i);
// 		if (!(ft_isdigit(line[i])) && (line[i] != ' ' && line[i] != '\n'))
// 		{
// 			printf("line[i]: %c i: %d\n", line[i], i);
// 			free_with_message(NULL, "Eroor\n");
// 		}
// 		i++;
// 	}
// 	if (argc < 3)
// 		free_with_message(NULL, "");
// }

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_to_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_new_save(save);
	return (line);
}
/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */