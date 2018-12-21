#include <stdio.h>
#include "libft.h"
#include "fillit.h"

t_tetr	**ft_tetr_make(char **tetrs, int count)
{
	t_tetr	**tts;
	int		i;

	if (!(tts = (t_tetr**)malloc(sizeof(t_tetr*) * (count))))
		return (NULL);
	tts[count] = NULL;
	i = 0;
	while (i < count)
	{
		if (!(tts[i] = ft_tetr_new(tetrs[i], i)))
			return (NULL);
		i++;
	}
	writing(tts); /////
	return (tts);
}

t_tetr	*ft_tetr_new(char *s, int count)
{
	t_tetr	*new;
	int		i;
	int		j;

	if (!(new  = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	if (!(new->x  = (int*)malloc(sizeof(int) * 4)) ||
				!(new->y  = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	new->p_x = 0;
	new->p_y = 0;
	new->c = count;
	i = -1;
	j = -1;
	while (++i < 20)
	{
		if (s[i] == "#")
		{
			new->x[++j] = i % 5;
			new->y[j] = i / 5;
		}
	}
	move_tetr(new); /////
	return (new);
}

void move_tetr(t_tetr *new)
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
		min_y = (min_y <= new->x[j]) ? min_y : new->x[j];
	}
	i = -1;
	while (++i < 4)
	{
		new->x[i] -= min_x;
		new->y[i] -= min_y;
	}
}

void	ft_free_tts(t_tetr **tts)
{
	// free all ints - DODELAT
	free (tts);
}
