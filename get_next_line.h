
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
// # define BUFFER_SIZE 42
# define BUFFER_SIZE 1 // Test

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);

#endif
