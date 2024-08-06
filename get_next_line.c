#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	int read_bytes;
	if (fd < 0 || BUFFER_SIZE < 0 || fd > FOPEN_MAX)
		return (NULL);
	line = NULL;

	if (*buffer)
	{
		line = ft_strjoin(line, buffer);
		if (to_find_newline(line) != -1)
		{
			to_clear_buffer(buffer);
			return (line);
		}
	}
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = 0;
		line = ft_strjoin(line, buffer);
		if (to_find_newline(line) != -1)
		{
			to_clear_buffer(buffer);
			return (line);
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (*buffer)
	{
		to_clear_buffer(buffer);
		return (line);
	}
	return (NULL);
}
// int	main()
// {
// 	int fd1 = open("test.txt", O_RDONLY);
// 	int fd2 = open("biblia.txt", O_RDONLY);
// 	 	test = get_next_line(fd1);
// 	 	test = get_next_line(fd2);

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

