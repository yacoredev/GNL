#include "get_next_line.h"

static int    get_line(char *buffer, int fd, char **rest)
{

    ssize_t         bytes;
    ssize_t         i;

    while(1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        // -1  -> read error
        if (bytes < 0)
        {
            free(*rest);
            *rest = NULL;
            return (-1);
        }
        // 0   -> EOF
        if (bytes == 0)
            return (0);
        buffer[bytes] = '\0';
        // kanfreey rest dakhl strjoin
        *rest = ft_strjoin(*rest, buffer);
        if (!*rest)
            return (-1);
        i = 0;
        while ((*rest)[i])
        {
            // 1   -> newline found
            if ((*rest)[i] == '\n')
                return (1);
            i++;
        }
    }
}

static char *extract_line(char *rest)
{
    int i;

    i = 0;
    while (rest[i])
    {
        if (rest[i] == '\n')
            return (ft_substr(rest, 0, i + 1));
        i++;
    }
    return (ft_strdup(rest));
}

static char *update_rest(char *rest)
{
    int end;
    int start;
    char *tmp;

    start = 0;
    while (rest[start] && rest[start] != '\n')
        start++;
    // mal9atx \n (7it mchat ta lakhir, \0 howa li khrjna)
    if (!rest[start])
    {
        free(rest);
        return (NULL);
    }
    // l9at \n w zdna 9dam
    start++;
    tmp = ft_substr(rest, start, ft_strlen(rest + start));
    if (!tmp)
    {
        free(rest);
        return (NULL);
    }
    free(rest);
    return (tmp);
}

// 3wd liha b linked list
char *get_next_line(int fd)
{
    char    *buffer;
    static char    *rest;
    char    *line;

    // if this condition kafi?
    if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);

    // IMP: matnsach tfree buffer at the end fhad function
    buffer = malloc((size_t)(BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    // if get_line return 0 ima tprinti null hit
    // file khawi or print dakchi li b9a flast line
    if (get_line(buffer, fd, &rest) < 0)
    {
        free(buffer);
        // free(rest);
        return (NULL);
    }
    // mybe khasni n3zal check dyal !*rest bach ila mab9a ta content nfreeyiha
    // but rani kan3awd nfreeha wst update_rest f (ft_substr)
    if (!rest)
    {
        free(buffer);
        return (NULL);
    }
    line = extract_line(rest);
    // momkin update.. trja3 null ghatwli rest = null
    // hna f akhir line kanfree rest but rah mazal copy dyalo f line
    rest = update_rest(rest);
    free(buffer);
    return (line);
}