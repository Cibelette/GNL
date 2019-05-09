/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:18:19 by clagier           #+#    #+#             */
/*   Updated: 2019/05/09 17:25:30 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NETXT_LINE_H
# define GET_NETXT_LINE_H

# define BUFF_SIZE 99

int get_next_line(const int fd, char **line);

#endif