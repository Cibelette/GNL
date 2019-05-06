/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:24 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/06 15:31:35 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int get_next_line(const int fd, char **line)
{
    char    buf[BUF_SIZE + 1];
    static  char    *rest;
    char    *ligne;
    char    *tmp;
    int     ret;
    size_t    i;
    size_t    j;

    while (tmp == NULL && ligne != NULL)
    {   
        i = 0;
        if (tmp == NULL)
        {
            ret = read(fd, buf, BUF_SIZE);
            buf[ret] = '\0';
            printf ("buf = %s\n", buf);
            if (rest != NULL)
                {
                    tmp = ft_strjoin(rest, buf);
                    printf ("tmp (rest + buf) = %s\n", tmp);
                }
            if (rest == NULL)
           		tmp = ft_strnew(ret);
			    tmp = ft_strcpy(tmp, buf);
                printf("tmp = %s\n", tmp);
        }
        while (tmp[i] != '\n' && (tmp[i] != 0)
            i++;
        if (tmp[i] == '\n')
        {
            ligne = ft_strncpy(ligne, rest, i);
            rest = ft_strcpy(rest, tmp + i)
            printf("ligne = %s, reste = %s\n", ligne, rest);
            return (0);
        }
        else
        {
            rest = ft_strcpy (rest, tmp);
            ft_strclr(tmp);
            printf("rest = %s, tmp = %s\n", rest, tmp);
        }
        
    } 
    return (0);  
}
    


int main()
{
    char **line;
    int fd;

    fd = open ("get_next_line.c", O_RDONLY);
    get_next_line(fd, line);
    return (0);
}