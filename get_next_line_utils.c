#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		totalsize;
	int		i;
	int		j;
	
	i = 0;
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (totalsize + 1));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		if (++i && s2[j++] == '\n')
			break;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

int	to_find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	to_clear_buffer(char *s1)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	i = -1;
	while (new[++i])
		s1[i] = new[i];
	s1[i] = '\0';
	free(new);
 }


 