#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**bufs;
	t_tetr	**tts;
	char	**map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetraminos_file\n");
		return (0);
	}
	if (!(bufs = (char**)malloc(sizeof(char*) * (26 + 1))))
		return (0);
	if (ft_file_work(argv[1], bufs) == 0)
		return (0);
	if (!(tts = ft_tetrs_make(bufs)))
		return (0);
	map = empty_map(ft_optimal_map_size(tts));
	map = ft_func1(map, tts, 0);
	ft_print_map(map);
	ft_free_tts(tts);
	//system("leaks fillit");
	return (0);
}
