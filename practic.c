#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;

    fd = open("file.txt", O_RDONLY);

    // free(get_next_line(fd));
    printf("%s", get_next_line(fd));

    close(fd);
    return (0);
}