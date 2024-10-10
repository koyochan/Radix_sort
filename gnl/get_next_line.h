/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:37 by kotkobay          #+#    #+#             */
/*   Updated: 2024/05/20 15:19:10 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../inc/push_swap.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_save(int fd, char *save);
char	*ft_strchr_c(char *s, int c);
char	*ft_strjoin_c(char *save, char *buff);
size_t	ft_strlen_c(char *s);
char	*ft_get_line(char *save);
char	*ft_new_save(char *save);

#endif
