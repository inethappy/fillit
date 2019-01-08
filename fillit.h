#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		s_tetr
{
	int			x[4];	// array of x coordinates
	int			y[4];	// array of y coordinates
	int			p_x;	// x position
	int			p_y;	// y position
	int			c;		// char 0 - 25 ????
}					t_tetr;

int					ft_buf_verif(char *buf);
int					ft_verif(char **bufs);
void				ft_free_bufs(char **bufs);

void				ft_tetr_move(t_tetr *new);
t_tetr				*ft_tetr_new(char *s, int count);
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
