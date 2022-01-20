#include "so_long.h"

void ft_print_moves(int x, t_game *player)
{
    char *str;
    str = ft_itoa(x);
    char *m;
    char *img;
    int w;
    int h;
    m = ft_strjoin("moves :",str);

    img = mlx_xpm_file_to_image(player->mlx, "image/block.xpm", &w, &h);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, 0 * BLOCK_SIZE, 0 * BLOCK_SIZE);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, 1 * BLOCK_SIZE, 0 * BLOCK_SIZE);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, 2 * BLOCK_SIZE, 0 * BLOCK_SIZE);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, 3 * BLOCK_SIZE, 0 * BLOCK_SIZE);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, 4 * BLOCK_SIZE, 0 * BLOCK_SIZE);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, 5 * BLOCK_SIZE, 0 * BLOCK_SIZE);


    mlx_string_put( player->mlx, player->mlx_win, 5, 5, 0x00ffffff, m);
    free(m);
}

int	key_hook(int keycode, t_game *player)
{
    if(keycode ==  53)
        exit(0);
    else if(keycode == D_KEY || keycode == A_KEY || keycode == W_KEY || keycode == S_KEY)
         ft_move(player,keycode);
    ft_printf_map(player->map);
    ft_print_moves(player->mv, player);
	return (0);
}

void ft_put_map_items(void *mlx, void *mlx_win, char **map, t_game *player)
{
    int     i;
    int     j;
    void    *img_ptr;
    int     w;
    int     h;

    w = BLOCK_SIZE;
    h = BLOCK_SIZE;
    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'P')
                img_ptr = mlx_xpm_file_to_image(mlx, "image/player.xpm", &w , &h);
            else if(map[i][j] == 'C')
                img_ptr = mlx_xpm_file_to_image(mlx, "image/apple.xpm", &w , &h);
            else if(map[i][j] == 'E')
            {
                player->exit_x = j;
                player->exit_y = i;
                img_ptr = mlx_xpm_file_to_image(mlx, "image/door.xpm", &w , &h);
            }
            else if (map[i][j] == '1')
                img_ptr = mlx_xpm_file_to_image(mlx, "image/block.xpm", &w , &h);
            else if(map[i][j] == 'X')
                img_ptr = mlx_xpm_file_to_image(mlx, "image/zoro.xpm", &w , &h);

            else
                img_ptr = mlx_xpm_file_to_image(mlx, "image/background.xpm", &w , &h);

                mlx_put_image_to_window(mlx, mlx_win, img_ptr, j * BLOCK_SIZE, i * BLOCK_SIZE);

            ++j;
        }
        ++i;
    }
}