/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:21:53 by cibyl             #+#    #+#             */
/*   Updated: 2019/05/03 01:18:19 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct node
{
    int data;
    struct node *p_next;
    struct  node *p_prev;
};

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

Dlist *dlist_append(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struc node *p_new = malloc (sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->data = data;
            p_new->p_next = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->prev = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_tail->p_next = p_new;
                p_new->p_prev = p_list->p_tail;
                p_list->p_tail = p_new;
                
            }
            p_list->length++;
        } 
    }
    return (p_list)
}

Dlist *dlist_prepend(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struc node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->data = data;
            p_new->p_prev = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->p_next = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_head->p_prev = p_new;
                p_new->p_next = p_list->p_head;
                p_list->p_head = p_new;
            }
            p_list->length++;
        }
    }
    return(p_list);
}

Dlist *dlist_insert(Dlist *p_list, int data, int position)
{
    if (p_list != NULL)
    {
        struct node *tmp = p_list->p_head;
        int i =1;
        while (tmp != NULL && i <= position)
        {
            if (position == i)
            {
                if (tmp->p_next == NULL)
                {
                    dlist_append(p_list, data);
                }
                else if (tmp->p_prev == NULL)
                {
                    dlist_prepend(p_list, data);
                }
                else
                {
                    struc node *p_new = malloc(sizeof *p_new);
                    if (p_new != NULL)
                    {
                        tmp->p_prev->p_next = p_new;
                        tmp->p_next->p_prev = p_new;
                        p_new->p_next = tmp->p_next;
                        p_new->p_prev = tmp->p_prev;
                    }
                }
                p_list->length++;
            }
            tmp = tmp->p_next;
            i++;
            }
        }
    }
    return (p_list);
}