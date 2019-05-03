/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:24 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/02 14:11:36 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUF_SIZE 5

typedef struct node
{
    char data;
    struct node *p_next;
    struct  node *p_prev;
}Dnode;

typedef struct dlist
{
    size_t  length;
    struct node *p_tail;
    struct node *p_head;
}Dlist;


Dlist *dlist_new(void)
{
    Dlist *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return (p_new);
}

int get_next_line(const int fd, char **line)
{
    char *buf[BUF_SIZE + 1];
    int ret;
    int i;
    dlist *file;

    i = 0;
    file = dlist_new();

    while (ret = read(fd, buf, BUF_SIZE));
    {
        line = ft_strsplit (ret, '/n');
        while (line)
        {
            
        }
    }
}