
#include"so_long.h"
#include"minilibx/mlx.h"
/**
 * @brief i tcheck if i have the char in my variable c in my map
 * 
 * @param map 
 * @param c the char who i want look in my map
 * @return int 
 */
int tcheck_char(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == c)
			return (1);
		j++;
		if (map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
	}
	return(0);
}