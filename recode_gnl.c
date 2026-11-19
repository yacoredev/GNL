#include "get_next_line.h"

static char *free_rest(char *rest)
{
	free(rest);
	return (NULL);
}

static int wach_kayn_newline(char *rest)
{
	int i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int get_line(char *buffer, char **rest)
{
	ssize_t bytes;

	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (0);
		if (bytes < 0)
			return (-1);
		*rest = ft_strjoin(*rest, buffer);
		if (*rest)
			return (-1);
		if (wach_kayn_newline(*rest))
			return (1);
	}
}

static char *extract_line(char **rest)
{
	char *line;
	int i = 0;

	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	// if i tcheck returning null f code principal?
	line = ft_substr(*rest, 0, i + 1);
	if (!line)
		return (free_rest(*rest));
}

static char *update_stash(char *rest)
{
	int i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			break;
		i++;
	}
	if (!rest[i])
	{
		// free rest return null
	}
	// return mn \n to \0
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	// jib line, or return error or EOF
	if (get_line(buffer, rest) < 0)
	{
		free(buffer);
		return (free_rest(rest));
	}
	
	// extarcti line
	line = extract_line(&rest);
	if (!line)
	{
		free(buffer);
		return (free_rest(rest));
	}
	rest = update_stash(rest);
}
