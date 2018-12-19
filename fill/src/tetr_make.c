#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
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
	return (new);
}

void	ft_free_tts(t_tetr **tts)
{
	// free all ints - DODELAT
	free (tts);
}
