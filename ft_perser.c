#include "so_long.h"
char *ft_make_matrix(int fd)
{
    char *tab;
    char *str;

    tab = NULL;
    str = readi(fd);
        while (str)
        {
            if(str[ft_strlen(str - 1)] == '\n')
             {
                printf("error");
                free(str);
                exit(0);
             }
            if(!tab)
             tab = ft_strdup(str);
            else
             tab = ft_strjoin(tab,str);
            free(str);
            str = readi(fd);
        }
    return(tab);
}
char *readi(int fd)
{
    char *buffer = ft_strdup("");
    char buff[1];
    int i = 1;
    while (i)
    {
        i = read(fd, buff, 1);
        if (i < 0)
        {
            free(buffer);
            return (NULL);
        }
        if (i == 0)
            break;
        buffer = ft_sstrjoin(buffer, buff);
        if (buff[0] == '\n')
            break;

    }
    if(buffer[0] == '\0')
    {
        free(buffer);
        return(NULL);
    }
    return buffer;
}
char    *ft_sstrjoin(char    *s1, char *c)
{
    char    *al;
    size_t  len;
    int     i;

    i = 0;
    len = ft_strlen(s1);
    al = malloc(len + 2);
    if (al == 0)
        return (0);
    while (s1[i])
    {
        al[i] = s1[i];
        i++;
    }
    al[len] = c[0];
    al[len + 1] = '\0';
    free(s1);
    return (al);
}