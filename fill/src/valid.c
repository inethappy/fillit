#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int ft_verif(char *buf)
{
	if (ft_count_char(buf, '\n') != 4 || ft_count_char(buf, '#') != 4
		|| ft_count_char(buf, '.') != 12)
		return (0);
	if (ft_str_len_n(buf, '\n') != 4 || ft_str_len_n(buf + 5, '\n') != 4
		|| ft_str_len_n(buf + 10, '\n') != 4 || ft_str_len_n(buf + 15, '\n') != 4)
		return (0);
 	return (1);
}

int main(void)
{
	char	buf[21];
	int		ret;
	int		fd;

	if ((fd = open("test", O_RDONLY)) < 3)
		return 0;
//	printf("fd = %d\n", fd);
	while ((ret = read(fd, buf, 20)) > 0)
	{
		buf[ret] = '\0';
		printf("ft_verif = %d\n", ft_verif(buf));
		printf("buf : \n%s\n", buf);
		//ret = read(fd, buf, 1);
		//if (buf[0]) = '\0';
	}

return 0;
}
