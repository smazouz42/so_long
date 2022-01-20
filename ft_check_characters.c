#include "so_long.h"
int ft_loop_for_cheater(char **loop)
{
    int x;
    int y;
    char s;

    x = 0;
    while(loop[x])
    {
        y = 0;
        while(loop[x][y])
        {
            s = loop[x][y];
            if(s != 'P' && s != 'E' && s != '1' && s != '0' && s != 'C' && s != 'X')
                return(0);
            y++;
        }
        x++;
    }
    return(1);
}
int ft_check_p_c_e(char **map)
{
    int x;
    int y;
    int player;
    int collectible;
    int map_exit;

    player = 0;
    collectible = 0;
    map_exit = 0;
    x = 0;
    while(map[x])
    {
        y = 0;
        while(map[x][y])
        {
            if(map[x][y] == 'P')
                player++;
            else if(map[x][y] == 'E')
                map_exit++;
            else if(map[x][y] == 'C')
                collectible++;
            y++;
        }
        x++;
    }
    if(player == 1 && collectible != 0 && map_exit != 0)
        return(1);
    else
     return(0);
}
int ft_collectible_count(char **map)
{
    int x;
    int y;
    int count;
    
    count = 0;
    x = 0;
    while(map[x])
    {
        y = 0;
        while(map[x][y])
        {
            if(map[x][y] == 'C')
                count++; 
            y++;
        }
        x++;
    }
    return(count);
}
