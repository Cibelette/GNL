/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:18:19 by clagier           #+#    #+#             */
/*   Updated: 2019/05/11 15:33:47 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NETXT_LINE_H
# define GET_NETXT_LINE_H

#include <stdlib.h>

# define BUFF_SIZE 50

typedef struct Plist
{	
	int		fd;
	size_t  lines;
 	struct line *t_tail;
}				p_list;

typedef struct		Tline
{
	char			*ligne;
	size_t			size;
	struct t_line	*next;
}					t_line;

int get_next_line(const int fd, char **line);

#endif