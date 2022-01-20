#include "so_long.h"
void ft_move_enemy(t_enemy *temp, t_game *player, int keycode)
{
    int next_pos_h;
    int next_pos_w;
    void *img;
    int w;
    int h;

    next_pos_h = temp->p_h - 1;
    next_pos_w = temp->p_w - 1;
    p_and_next_e(keycode,&next_pos_h,&next_pos_w,player);
    if (player->map[next_pos_h][next_pos_w] == '1' || player->map[next_pos_h][next_pos_w] == 'X' || player->map[next_pos_h][next_pos_w] == 'C' || player->map[next_pos_h][next_pos_w] == 'E')
        return ;
    if(player->map[next_pos_h][next_pos_w] == '0')
    {
        player->map[next_pos_h][next_pos_w] = 'X';
        player->map[temp->p_h - 1][temp->p_w - 1] = '0';
    }
    if(player->map[next_pos_h][next_pos_w] == 'P')
    {
        printf("\x1B[31m game over");
        exit(0);
    }
    img = mlx_xpm_file_to_image(player->mlx, "image/zoro.xpm", &w, &h);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, next_pos_w * BLOCK_SIZE, next_pos_h * BLOCK_SIZE);
    img = mlx_xpm_file_to_image(player->mlx, "image/background.xpm", &w, &h);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, (temp->p_w - 1) * BLOCK_SIZE, (temp->p_h - 1) * BLOCK_SIZE);
    p_and_next_e(keycode,&temp->p_h,&temp->p_w,player);
}
void ft_move_enemys(t_game *player,int keycode)
{

    t_enemy *temp;

    temp = player->enemy;
    while(temp)
    {
        ft_move_enemy(temp, player, keycode);
        temp = temp->next;
    }
}
void ft_move(t_game *player, int keycode)
{
    int next_pos_h;
    int next_pos_w;
    void *img;
    int w;
    int h;

    next_pos_h = player->p_h - 1;
    next_pos_w = player->p_w - 1;
    p_and_next_p(keycode,&next_pos_h,&next_pos_w,player);
    if(player->map[next_pos_h][next_pos_w] == '1')
        return ;
    if(player->map[next_pos_h][next_pos_w] == 'X')
    {
        printf("\x1B[31m game over");
        exit(0);
    }
    else if(player->map[next_pos_h][next_pos_w] == 'E')
    {
        if (player->collectible == 0)
        {
            printf("\x1B[32m You win!");
            exit(0);
        }
        else
            return ;
    }
    else if(player->map[next_pos_h][next_pos_w] == 'C')
    {
        player->map[player->p_h - 1][player->p_w - 1] = '0';
        player->map[next_pos_h][next_pos_w] = 'P';
        player->collectible--;
    }
    else if(player->map[next_pos_h][next_pos_w] == '0')
    {
        player->map[next_pos_h][next_pos_w] = 'P';
        player->map[player->p_h - 1][player->p_w - 1] = '0';
    }
    img = mlx_xpm_file_to_image(player->mlx, "image/player.xpm", &w, &h);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, next_pos_w * BLOCK_SIZE, next_pos_h * BLOCK_SIZE);
    img = mlx_xpm_file_to_image(player->mlx, "image/background.xpm", &w, &h);
    mlx_put_image_to_window(player->mlx, player->mlx_win, img, (player->p_w - 1) * BLOCK_SIZE, (player->p_h - 1) * BLOCK_SIZE);
    p_and_next_p(keycode,&player->p_h,&player->p_w,player);
    player->mv++;
    ft_move_enemys(player,keycode);

}