/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:01:41 by smazouz           #+#    #+#             */
/*   Updated: 2022/01/19 16:11:06 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void find_enemys_p(char **map, t_enemy **enemy)
{
    int x;
    int y;
    int nod;

    x = 0;
    nod = 1;
    while(map[x])
    {
        y = 0;
        while(map[x][y])
        {
            if(map[x][y] == 'X')
            {
                if(nod == 1)
                {
                    (*enemy) = ft_lstnew(x + 1, y + 1);
                    nod++;
                }
                else
                {
                    ft_lstadd_back(enemy,ft_lstnew(x + 1, y + 1));
                    nod++;
                }
            }
            y++;
        }
        x++;
    }
}
static void animation_player(t_game *p)
{
    //void *mg_ptr;
    int h;
    int n;

    p->animation_[0]= mlx_xpm_file_to_image(p->mlx, "image/sanji1.xpm", &n , &h);
    p->animation_[1]= mlx_xpm_file_to_image(p->mlx, "image/sanji2.xpm", &n , &h);
    p->animation_[2]= mlx_xpm_file_to_image(p->mlx, "image/sanji3.xpm", &n , &h);
    p->animation_[3]= mlx_xpm_file_to_image(p->mlx, "image/sanji4.xpm", &n , &h);
    p->animation_[4]= mlx_xpm_file_to_image(p->mlx, "image/sanji5.xpm", &n , &h);
    p->animation_[5]= mlx_xpm_file_to_image(p->mlx, "image/sanji6.xpm", &n , &h);
}
static void animation_left(t_game *p)
{
    int h;
    int w;
     p->animation_left[0]= mlx_xpm_file_to_image(p->mlx, "image/sanji1_left.xpm", &w, &h);
     p->animation_left[1]= mlx_xpm_file_to_image(p->mlx, "image/sanji2_left.xpm", &w, &h);
     p->animation_left[2]= mlx_xpm_file_to_image(p->mlx, "image/sanji3_left.xpm", &w, &h);
     p->animation_left[3]= mlx_xpm_file_to_image(p->mlx, "image/sanji4_left.xpm", &w, &h);
     p->animation_left[4]= mlx_xpm_file_to_image(p->mlx, "image/sanji5_left.xpm", &w, &h);
     p->animation_left[5]= mlx_xpm_file_to_image(p->mlx, "image/sanji6_left.xpm", &w, &h);
}
 void ft_game(char **map)
{
    t_game p;
    int h;
    int w;
    t_enemy *enemy;
    enemy = NULL;
    if(!*map)
        return ;
    find_player_p(&p, map);
    p.map = map;
    p.mv = 0;
    w = ft_strlen(map[0]);
    h = ft_height_of_map(map);
    p.collectible = ft_collectible_count(map);
    find_enemys_p(p.map,&enemy);
    p.enemy = enemy;
    p.mlx = mlx_init();
	p.mlx_win = mlx_new_window(p.mlx, w * BLOCK_SIZE , h * BLOCK_SIZE, "so_long");
    animation_player(&p);
    animation_left(&p);
    mlx_loop_hook(p.mlx, animation, &p);
    ft_put_map_items(p.mlx, p.mlx_win, p.map, &p);
    mlx_hook(p.mlx_win,2,0,key_hook, &p);
    mlx_hook(p.mlx_win,17,0,ft_exit,NULL);
    mlx_loop(p.mlx);
}