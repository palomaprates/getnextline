/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:10:15 by pprates-          #+#    #+#             */
/*   Updated: 2024/08/15 11:12:03 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_bytes;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (*buffer)
	{
		line = ft_strjoin(line, buffer);
		if (to_find_newline(line) != -1)
			return (to_clear_buffer(buffer), line);
	}
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = 0;
		line = ft_strjoin(line, buffer);
		if (to_find_newline(line) != -1)
			return (to_clear_buffer(buffer), line);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (*buffer)
		return (to_clear_buffer(buffer), line);
	return (NULL);
}

// int	main()
// {
// 	int fd = open("teste.txt", O_RDONLY);
// 	int	i = 0;
// 	char *test;
// 	while (i < 6)
// 	{
// 	 	test = get_next_line(fd);
// 		printf("gnl: %s", test);
// 		free(test);
// 		i++;
// 	}
// 	return (0);
// }
