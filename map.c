#include "libft.h"
#include "fillit.h"

char **empty_map(int c)
{
	char **map;
	int	i;
	int j;
	int size;

	size = c * 4;
	i = 0;
	while ((i * i) < size)
		i++;
	if (!(map = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	map[i] = NULL;
	j = -1;
	while (++j < i)
		{
			map[j] = ft_strnew(i);
			ft_memset(map[j], '.', i);
		}
	//for printf:
	j = -1;
	printf("empty map:\n");
	while (map[++j])
		printf("%s\n", map[j]);
	printf("\n");
	return (map);
}


void ft_put_figure(char **map, t_tetr **tts, int fig)
{
	int j = -1;

	while (++j < 4)
		map[tts[fig]->y[j] + tts[fig]->p_y][tts[fig]->x[j] + tts[fig]->p_x] = 65 + fig;
	
}

int ft_func1(char **map, t_tetr **tts, int fig)
{
	int j;

	if (ft_put_check(map, tts, fig))
	{
		ft_put_figure(map, tts, fig);
		ft_func1(map, tts, fig + 1);
	}
	else
	{
		ft_free_bufs(map);// may seqfault
		map = empty_map(size + 1);
		j = -1;
		while (tts[++j])
			ft_tetr_move(tts[j]);
	}
 	//while (++j < 4)
	//	map[tts[fig]->y[j]][tts[fig]->x[j]] = 65 + fig;
}
