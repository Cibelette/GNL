/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNLtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:24 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/06 16:46:46 by clagier          ###   ########.fr       */
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
	
	ligne = NULL;
	tmp = NULL;
    i = 0;
	while (ligne == NULL)
   	{
		if (tmp == NULL)
		{
   	    	ret = read(fd, buf, BUF_SIZE);
			buf[ret] = '\0';
       		//printf ("buf = %s\n", buf);
       		if (rest != NULL)
			{   
				tmp = ft_strnew(ret + strlen(rest));         
				tmp = ft_strjoin(rest, buf);
				//printf ("tmp (rest + buf) = %s\n", tmp);
			}
    		if (rest == NULL)
			{
				tmp = ft_strnew(ret);
				tmp = ft_strcpy(tmp, buf);
				//printf("tmp = %s\n", tmp);
			}
		}
		while (tmp[i] && tmp[i] != '\n')
			i++;
		printf("%s, %d\n", tmp, tmp[1]);
		if (tmp[i] == '\n')
 		{
			ligne = ft_strnew(i );
			ligne = strncpy(ligne, tmp, i);
			ligne[i + 1] = '\0';
			rest = ft_strcpy(rest, tmp + (i + 1));
			//printf("ligne = %s, reste = %s\n", ligne, rest);
			*line = ligne;
			return (1);
		}
		else if (tmp[i] == '\0')
		{				
			rest = ft_strnew(ft_strlen(tmp));
			ft_strcpy(rest, tmp);
			tmp = NULL;
			free(tmp);
			//printf("rest = %s et tmp = %s\n", rest, tmp);
		}
	}
	return (-1); 
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
		}
	}
	return (0);
}