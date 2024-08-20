/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:10:15 by pprates-          #+#    #+#             */
/*   Updated: 2024/08/20 16:38:58 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1][FOPEN_MAX];
	int			read_bytes;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (*buffer[fd])
	{
		line = ft_strjoin(line, buffer[fd]);
		if (to_find_newline(line) != -1)
			return (to_clear_buffer(buffer[fd]), line);
	}
	read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[fd][read_bytes] = 0;
		line = ft_strjoin(line, buffer[fd]);
		if (to_find_newline(line) != -1)
			return (to_clear_buffer(buffer[fd]), line);
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
	}
	if (*buffer[fd])
		return (to_clear_buffer(buffer[fd]), line);
	return (NULL);
}

// int	main()
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	int	fd2 = open("test2.txt", O_RDONLY);
// 	char	*test;
// 	int	i = 0;

// 	while (i < 12)
// 	{
// 		if (i % 2 == 0)
// 			test = get_next_line(fd);
// 		else
// 			test = get_next_line(fd2);
// 		printf("%s", test);
// 		i++;
// 	}
// 	return (0);
// }
