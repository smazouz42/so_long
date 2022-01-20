/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:05:44 by smazouz           #+#    #+#             */
/*   Updated: 2022/01/20 12:04:14 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int ft_exit(void *str)
{
    str = NULL;
    exit(0);
    return (0);
}

int animation(t_game *player)
{
    static int  img_counter;
    static int  duration_counter;

    if (img_counter == 5)
    {
        img_counter = 0;
        duration_counter = 0;
    }
    if (duration_counter == 5)
    {
        ++img_counter;
        duration_counter = 0;
    }
     if (player->status == 'L')
        mlx_put_image_to_window(player->mlx, player->mlx_win, player->animation_left[img_counter], (player->p_w - 1) * BLOCK_SIZE, (player->p_h - 1) * BLOCK_SIZE);
     else
        mlx_put_image_to_window(player->mlx, player->mlx_win, player->animation_[img_counter], (player->p_w - 1) * BLOCK_SIZE, (player->p_h - 1) * BLOCK_SIZE);
    ++duration_counter;
    return(0);
}
int main(int ac, char **av)
{
    char *tab;
    char **tab2;
    int fd;
    int x;
    int y;

    x = 0;
    y = 0;

    if(ac == 2)
    {
        if(ft_name_of_map(av[1]) == 0)
        {
            printf("name of map incorrect");
            return(0);
        }
        fd  = open(av[1], O_RDWR);
        if(fd == -1)
        {
            perror(av[1]);
            exit(0);
        }
        tab = ft_make_matrix(fd);
        if (!tab || !*tab)
           exit(0);
        if(tab[ft_strlen(tab) - 1] == '\n')
            {
    
                printf("error");
                exit(0);
            }
        tab2 = ft_split(tab,'\n');
        ft_check_map(tab2);
    }
    else
	{
		printf("there is an error in argc");
		return(0);
	}
    ft_game(tab2);
        return(0);
}