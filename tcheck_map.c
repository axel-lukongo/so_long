#include"so_long.h"
#include"minilibx/mlx.h"

void	tcheck_map(char **map)
{
	if (tcheck_char(map, '1') == 0)
	{
		ft_printf("must have a wall");
		exit(0);
	}
	if (tcheck_char(map, 'E') == 0)
	{
		ft_printf("must have a exit");
		exit(0);
	}
	if (tcheck_char(map, 'C') == 0)
	{
		ft_printf("must have collectable");
		exit(0);
	}
	if (tcheck_char(map, 'P') == 0)
	{
		ft_printf("must have a personage");
		exit(0);
	}
}

void contour_map(char **map)
{
	int	i;
	int	j;
	int width;

	i = 0;
	j = 0;
	width = ft_strlen(map[0]);
	while (map[i][j])
	{
		j++;
		if (map[i][j] == '\n')
		{
			if (map[i][0] != '1' || map[i][j - 1] != '1' || j > width)
			{
				ft_printf("derniere case map = %c\n", map[i][j-1]);
				ft_printf("map ain't close by a wall");
				exit(1);
			}
			i++;
			j = 0;
		}
	}
}

/**
 * @brief in this fonction i tcheck if i the file name finish by .ber else i exit
 * 
 * @param file this is the name of the file where i store my map
 */
void	name_map(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
			if (file[i + 1] == 'b')
				if (file[i + 2] == 'e')
					if (file[i + 3] == 'r')
						if (file[i + 4] == '\0')
							return ;
		i++;
	}
	ft_printf("file must finish by .ber");
	exit (1);
}