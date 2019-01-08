#include "fillit.h"

void ft_tetr_move(t_tetr *new)
{
	int i;
	int j;
	int min_x;
	int min_y;

	i = 0;
	j = -1;
	while (++j < 4)
	{
		while (++i < 4)
			{
				min_x = (new->x[i] <= new->x[i - 1]) ? new->x[i] : new->x[i - 1];
				min_y = (new->y[i] <= new->y[i - 1]) ? new->y[i] : new->y[i - 1];
			}
		min_x = (min_x <= new->x[j]) ? min_x : new->x[j];
		min_y = (min_y <= new->y[j]) ? min_y : new->y[j];
	}
	i = -1;
	while (++i < 4)
	{
		new->x[i] -= min_x;
		new->y[i] -= min_y;
	}
}

t_tetr	*ft_tetr_new(char *s, int count)
{
	t_tetr	*new;
	int		i;
	int		j;

	if (!(new  = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
/*	if (!(new->x  = (int*)malloc(sizeof(int) * 4)) ||
				!(new->y  = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
*/	new->p_x = 0;
	new->p_y = 0;
	new->c = count;
	i = -1;
	j = -1;
	while (++i < 20)
	{
		if (s[i] == '#')
		{
			new->x[++j] = i % 5;
			new->y[j] = i / 5;
		}
	}
	ft_tetr_move(new);
	return (new);
}

t_tetr	**ft_tetrs_make(char **bufs)
{
	t_tetr	**tts;
	int		i;

	i = 0;
	while(bufs[i])
		i++;
	if (!(tts = (t_tetr**)malloc(sizeof(t_tetr*) * (i + 1))))
		return (NULL);
	tts[i] = NULL;
	i = 0;
	while (bufs[i])
	{
		if (!(tts[i] = ft_tetr_new(bufs[i], i)))
			return (NULL);
		i++;
	}
	//writing(tts, i); /////
	return (tts);
}

void	ft_free_tts(t_tetr **tts)
{
	/*int		i;

	i = 0;
	while (tts[i])
		free(tts[i++]);*/
	free (tts);
}


