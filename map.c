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
	int		i;
	int		size;

	size = ft_strlen(map[0]);
	i = 0;
	while (i < size * size)
	{
		if (ft_put_check(map, tts, fig, size))
		{
			ft_put_figure(map, tts, fig);
			if (ft_func1(map, tts, fig + 1))
				return (1);
			ft_erase_figure(map, tts, fig);
		}
		i++;
		tts[fig]->p_x = i % size;
		tts[fig]->p_y = i / size;
	}
	ft_free_bufs(map);// may seqfault
	map = empty_map(size + 1);
	i = -1;
	while (tts[++i])
		ft_tetr_move(tts[i]);

 	//while (++j < 4)
	//	map[tts[fig]->y[j]][tts[fig]->x[j]] = 65 + fig;
}

int		ft_put_check(char **map, t_tetr **tts, int fig, int size)
{

	int		i;

	i = -1;
	while (++i < 4)
		if ((tts[fig]->p_y + tts[fig]->y[i] >= size) || (tts[fig]->p_x + tts[fig]->x[i] >= size))
			return (0);
	i = -1;
	while (++i < 4)
		if (map[tts[fig]->p_y + tts[fig]->y[i]][tts[fig]->p_x + tts[fig]->x[i]] != '.')
			return(0);
	return(1);
}
