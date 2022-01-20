#include "so_long.h"
void p_and_next_e(int keycode, int *p_h, int *p_w, t_game *player)
{
    if(keycode == D_KEY)
    {
        if(player->p_w > player->enemy->p_w)
            (*p_w)++;
        else 
            (*p_w)--;
        player->status = 'R';
    }
    else if(keycode == A_KEY)
    {
        if(player->p_w < player->enemy->p_w)
            (*p_w)--;
        else 
            (*p_w)++;
        player->status = 'L';
    }
    else if(keycode == W_KEY)
    {
        if(player->p_h < player->enemy->p_h)
            (*p_h)--;
        else
            (*p_h)++;
    }
    else if(keycode == S_KEY)
    {
        if(player->p_h > player->enemy->p_h)
            (*p_h)++;
        else
            (*p_h)--;
    }

}
void p_and_next_p(int keycode, int *p_h, int *p_w, t_game *player)
{
    if(keycode == D_KEY)
    {
        player->status = 'R';
        (*p_w)++;
    }
    else if(keycode == A_KEY)
    {
        (*p_w)--;
        player->status = 'L';
    }
    else if(keycode == W_KEY)
        (*p_h)--;
    else if(keycode == S_KEY)
        (*p_h)++;

}
void find_player_p(t_game *player, char **map)
{
    int x;
    int y;

    x = 0;
    while(map[x])
    {
        y = 0;
        while(map[x][y])
        {
            if(map[x][y] == 'P')
            {
                player->p_h = x + 1;
                player->p_w = y + 1;
                return ;
            }
            y++;
        }
        x++;
    }
}