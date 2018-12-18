#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int ft_tetr_verif(char *buf)
{
	if (ft_count_char(buf, '\n') != 4 || ft_count_char(buf, '#') != 4
		|| ft_count_char(buf, '.') != 12)
		return (0);
	if (ft_str_len_n(buf, '\n') != 4 || ft_str_len_n(buf + 5, '\n') != 4
		|| ft_str_len_n(buf + 10, '\n') != 4 || ft_str_len_n(buf + 15, '\n') != 4)
		return (0);
	//test on neibourse
 	return (1);
}

int		ft_verif(char **tetrs)
{
	char	buf[21];
	int		ret;
	int		fd;
	int		i;

	i = -1;
	if ((fd = open("test1.txt", O_RDONLY)) < 3)
		return 0;
	while ((ret = read(fd, buf, 20)) > 0 && ++i < 26)
	{
		buf[ret] = '\0';
		if (ret != 20 || ft_tetr_verif(buf) == 0 || ((tetrs[i] = ft_strdup(buf)) == NULL))
			return (0);
		//	printf("ft_verif = %d\n", ft_tetr_verif(buf));
		//	printf("buf : \n%s\n", buf);
		ret = read(fd, buf, 1);
		if (buf[0] == '\0')
			return(1);
		if (buf[0] != '\n')
			return (0);
	}
	return (0);
}

int main(void)
{
	char	**val_tetrs;


	val_tetrs = ft_verif();
	if (val_tetrs == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}



return 0;
}
