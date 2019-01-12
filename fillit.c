#include "fillit.h"

int main(int argc, char **argv)
{
	char	**bufs;
	t_tetr	**tts;
	int		i;
	int		tmp;

	if (argc != 2)
	// usage ?!
	i = 0;
	bufs = (char**)malloc(sizeof(char*) * (26 + 1));
	while (i < 27 && bufs[i]) ////
		bufs[i++] = NULL;
	if (ft_verif(bufs, argv[1]) == 0)
	{
		write(1, "error\n", 6);
		ft_free_bufs(bufs);
//		system("leaks a.out");
		return (0);
	}

/*	/////  pechat schitanih strok
	tmp = -1;
	while (bufs[++tmp])
	{
		printf("TETR %d:\n%s\n", tmp, bufs[tmp]);
	}
*/	//sozdanie tetraminov iz strok:
	if (!(tts =	ft_tetrs_make(bufs)))
		return (0);

	char **map;
	
	map = empty_map(ft_optimal_map_size(tts));
	map = ft_func1(map, tts, 0);
	ft_print_map(map);

	

	//ft_free_tts(tts);

//	system("leaks a.out");
	return (0);
}
