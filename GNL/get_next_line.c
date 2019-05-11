/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:24 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/11 16:41:54 by clagier          ###   ########.fr       */
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

	if (fd < 0 || fd > 1024 )
		return (-1);
	ligne = NULL;
	tmp = NULL;
	while (ligne == NULL)
   	{
		i = 0; 
		if (tmp == NULL)
		{
   	    	if((ret = read(fd, buf, BUFF_SIZE)) == -1)
			   	return (-1);
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
					if (rest[0] == '\0')
						return (0);
					if(rest[i] != '\0')
						rest = ft_strcpy(rest, rest + (i + 1));
					else
					{	
						if (rest[i - 1] == '\n' && rest[i] == '\n' && rest [i - 2] != '\n')
							return (0);
						rest = NULL;
					}
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
			rest = ft_strtrim(rest);
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