/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:24 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/09 17:25:35 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char *create_tmp(char *rest, char *tmp, char *buf, int ret)
{
	if (rest != NULL)
	{   
		tmp = ft_strnew(ret + strlen(rest));         
		tmp = ft_strjoin(rest, buf);
	}
    if (rest == NULL)
	{
		tmp = ft_strnew(ret);
		tmp = ft_strcpy(tmp, buf);
	}
	return (tmp);
}

int get_next_line(const int fd, char **line)
{
    char    buf[BUFF_SIZE + 1];
    static  char    *rest;
    char    *ligne;
    char    *tmp;
    int     ret;
    size_t    i;

	ligne = NULL;
	tmp = NULL;
	while (ligne == NULL)
   	{
		i = 0; 
		if (tmp == NULL)
		{
   	    	ret = read(fd, buf, BUFF_SIZE);
			buf[ret] = '\0';
			if (buf[0] == 0)
			{	
				if (rest != NULL)
				{	
					while (rest[i] && rest[i] != '\n')
						i++;
					ligne = ft_strnew(i + 1);
					ligne = strncpy(ligne, rest, i);
					*line = ligne;
					if(rest[i] != '\0')
						rest = ft_strcpy(rest, rest + (i + 1));
					else 
						rest = NULL;
					return (1);
				}
				return (0);
			}
       		else
				tmp = create_tmp(rest, tmp, buf, ret);
		}
		while (tmp[i] && tmp[i] != '\n')
			i++;
		if (tmp[i] == '\n')
 		{
			ligne = ft_strnew(i + 1);
			ligne = strncpy(ligne, tmp, i);
			ligne[i + 1] = '\0';
			rest = ft_strnew(ft_strlen(tmp + (i + 1)));
			rest = ft_strcpy(rest, tmp + (i + 1));
			*line = ligne;
			return (1);
		}
		else if (tmp[i] == '\0')
		{			
			rest = ft_strnew(ft_strlen(tmp));
			ft_strcpy(rest, tmp);
			tmp = NULL;
			free(tmp);
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
			ft_putstr("end");
			ft_putchar('\n');
			free(line);
		}
	}
	return (0);
}