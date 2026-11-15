#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;

    fd = open("file.txt", O_RDONLY);

    // free(get_next_line(fd));
    
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    
    
    // char *re = get_next_line(fd);
    // if (re == NULL)
    //     printf("NULL");
    // else
    //     printf("%s\n", re);

    close(fd);
    return (0);
}