/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:26 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 13:58:42 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include    <fcntl.h>
# include    <stdlib.h>
# include    <unistd.h>

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isnewline(char *str);
char	*free_smth(char *str);
char	*ft_getline(char *memory);
char	*ft_freememory(char *memory);
char	*get_next_line(int fd);

#endif
