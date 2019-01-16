/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:52:51 by okuchko           #+#    #+#             */
/*   Updated: 2019/01/16 15:56:18 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_tetr
{
	int			x[4];
	int			y[4];
	int			p_x;
	int			p_y;
}					t_tetr;

int					ft_buf_verif(char *buf);
int					ft_file_work(char *file_name, char **bufs);
int					ft_verif(int fd, char **bufs);
void				ft_free_bufs(char **bufs);

void				ft_tetr_move(t_tetr *new);
t_tetr				*ft_tetr_new(char *s);
t_tetr				**ft_tetrs_make(char **bufs);
void				ft_free_tts(t_tetr **tts);

int					ft_optimal_map_size(t_tetr **tts);
char				**empty_map(int i);
char				**ft_func1(char **map, t_tetr **tts, int fig);
int					ft_func2(char **map, t_tetr **tts, int fig, int size);
int					ft_put_check(char **map, t_tetr **tts, int fig, int size);

void				ft_paste_figure(char **map, t_tetr **tts, int fig);
void				ft_erase_figure(char **map, t_tetr **tts, int fig);
void				ft_print_map(char **map);

#endif
