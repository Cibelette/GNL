/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:24 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/04 15:14:54 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int get_next_line(const int fd, char **line)
{
    char    buf[BUF_SIZE + 1];
    static  char    *rest;
    char    *ligne;
    int     ret;
    size_t    i;
    char j;

    i = 1;
    if (rest == NULL)
    {
        ret = read(fd, buf, BUF_SIZE);
        buf[ret] = '\0';
        rest = ft_strdup(buf);
    }
    while (rest[i - 1 ] != '\n')
    {
        if (rest[i] == '\0')
        {   
            ret = read (fd, buf, BUF_SIZE);
            rest = ft_strjoin(rest, buf);
        }
        i++;
    }
    if (rest[i - 1] == '\n')
    {
        ligne = strndup(rest, i);
        rest = strchr(rest , (int)'\n');
        rest = ft_strtrim(rest);
    }
     printf("ligne = %s\n", ligne);
    return (0);
}


int main()
{
    char **line;
    int fd;

    fd = open ("ABC", O_RDONLY);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    return (0);

}