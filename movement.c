#include"so_long.h"
#include"minilibx/mlx.h"

void move_right(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
		{
			if(data->map[x][y] == 'p')
			{
				if(data->map[x][y + 1] != '1')
				{
					data->map[x][y + 1] = 'p';
					data->map[x][y] = '0';
				}
				break;
			}
			if(data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
		}
		destroy(data);
		init_struct(data);
		print_image(*data);
}

void move_left(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
		{
			if(data->map[x][y] == 'p')
			{
				if(data->map[x][y - 1] != '1')
				{
					data->map[x][y - 1] = 'p';
					data->map[x][y] = '0';
				}
				break;
			}
			if(data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
		}
		destroy(data);
		init_struct(data);
		print_image(*data);
}
void move_up(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
		{
			if(data->map[x][y] == 'p')
			{
				if(data->map[x + 1][y] != '1')
				{
					data->map[x + 1][y] = 'p';
					data->map[x][y] = '0';
				}
				break;
			}
			if(data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
		}
		destroy(data);
		init_struct(data);
		print_image(*data);
}
void move_down(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
		{
			if(data->map[x][y] == 'p')
			{
				if(data->map[x - 1][y] != '1')
				{
					data->map[x - 1][y] = 'p';
					data->map[x][y] = '0';
				}
				break;
			}
			if(data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
		}
		destroy(data);
		init_struct(data);
		print_image(*data);
}