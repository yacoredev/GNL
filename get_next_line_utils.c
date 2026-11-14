#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
        size_t  count;

        count = 0;
        while (s[count])
                count++;
        return (count);
}

char    *ft_strdup(const char *s)
{
        char    *str;
        char    *tmp;

        str = malloc(ft_strlen(s) + 1);
        if (!str)
                return (NULL);
        tmp = str;
        while (*s)
                *tmp++ = *s++;
        *tmp = '\0';
        return (str);
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
        size_t  len_dst;
        size_t  len_src;
        size_t  i;

        len_src = ft_strlen(src);
        len_dst = 0;
        while (dst[len_dst] && len_dst < size)
                len_dst++;
        if (len_dst == size)
                return (len_src + size);
        i = 0;
        while (src[i] && len_dst + i < size - 1)
        {
                dst[len_dst + i] = src[i];
                i++;
        }
        dst[len_dst + i] = '\0';
        return (len_src + len_dst);
}

char    *ft_strjoin(char *s1, char const *s2)
{
        char    *concat;
        size_t  size;

        if (!s1 && !s2)
                return (ft_strdup(""));
        if (s1 && !s2)
                return (ft_strdup(s1));
        if (!s1 && s2)
                return (ft_strdup(s2));
        size = ft_strlen(s1) + ft_strlen(s2) + 1;
        concat = malloc(size);
        if (!concat)
                return (NULL);
        concat[size] = '\0';
        ft_strlcat(concat, s1, size);
        ft_strlcat(concat, s2, size);
        free(s1);
        return (concat);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *sub;
        size_t  allowed_len;

        if (!s)
                return (NULL);
        if (start >= ft_strlen(s))
                return (ft_strdup(""));
        allowed_len = ft_strlen(s + start);
        if (allowed_len > len)
                allowed_len = len;
        sub = malloc(allowed_len + 1);
        if (!sub)
                return (NULL);
        
        // momkin nghyar strlcpy b strlcat? bach tb9a gher function whda
        
        ft_strlcat(sub, s + start, allowed_len + 1);
        return (sub);
}