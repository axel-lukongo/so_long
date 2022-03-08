#include"so_long.h"



int count_line(char *file)
{
	int	fd;
	int	nb_line;
	char	*str;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while(str)
	{
		nb_line++;
		str = get_next_line(fd);
	}
	close(fd);
	return(nb_line);
}

char **init_map(char **map)
{
	int	i;
	int	fd;
	int	nb_line;

	nb_line = count_line("map/map.ber");
	i = 0;
	map = malloc(sizeof(char *) * nb_line);
	fd = open("map/map.ber", O_RDONLY);
	map[i] = get_next_line(fd); 
	while(map[i])
	{
		i++;
		map[i] = get_next_line(fd); 
	}
	return(map);
}