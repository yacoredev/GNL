#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int c, char **v)
{
    int     fd;
    (void)c;
    fd = open(v[1], O_RDONLY);

    // free(get_next_line(fd));
    
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    // NULL
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    
    close(fd);
    return (0);
}