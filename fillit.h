#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		s_tetr
{
	int			*x;	// x[4]?	// array of x coordinates
	int			*y;		// array of y coordinates
	int			p_x;	// x position
	int			p_y;	// y position
	int			c;		// char 0 - 25 ????
}					t_tetr;

int					ft_buf_verif(char *buf);
int					ft_verif(char **bufs);
void				ft_free_bufs(char **bufs);

t_tetr				**ft_tetrs_make(char **bufs);
t_tetr				*ft_tetr_new(char *s, int count);
void				ft_tetr_move(t_tetr *new);
void				ft_free_tts(t_tetr **tts);


#endif
