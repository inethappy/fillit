#include <unistd.h>

int verif(char *buf)
{
	int i = 0;
	int n = 0;		
	int dot = 0;
	int hash = 0;
	while (buf[i])
		{
			if (buf[i] == '\n')
 		{
 			if (i != 4 || i != 9 || i != 14 || i != 19)
 				break ;
 			n++;
 		}
 		else if (buf[i] == '#')
 			hash++;
 		else if (buf[i] == '.')
 			dot++;
 		i++;
 	}
 	if ((n + dot + hash) == 21)
 		return 1;
 	return 0;	
}

int main(int argc, char const *argv[])
{
	char *buf;
	int count_reads = 0;
	int i = 0;	
 
 	while (count_reads < 26)
 	{
 		if (read(0, buf, 21) < 0)
 			break ;
 		while (read(0, buf, 21) > 0)
 		{
 			if (verif(buf) == 1)

 			
 		}
	}
return 0;
}
