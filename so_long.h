#ifndef SO_LONG_H
#define SO_LONG_H

#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#define W_KEY 13
#define D_KEY 2
#define A_KEY 0
#define S_KEY 1
#define ESC_key 53
#define BLOCK_SIZE 70

typedef struct s_enemy
{
	int p_h;
	int p_w;
	struct s_enemy *next;
} t_enemy;

typedef struct 	s_struct {
	int p_h;
    int p_w;
	int  collectible;
	int mv;
	int exit_y;
	int exit_x;
	void *animation_[6];
	void *animation_left[6];
	void *mlx;
	void *mlx_win;
	char status;
	char **map;
	t_enemy *enemy;
}			t_game;


t_enemy	*ft_lstlast(t_enemy *lst);
void	ft_lstadd_back(t_enemy **enemy, t_enemy *new);
t_enemy	*ft_lstnew(int p_h, int p_w);

void ft_move_right_enemy(t_game *player);
void ft_move_left_enemy(t_game *player);
void ft_move_up_enemy(t_game *player);
void ft_move_down_enemy(t_game *player);
void ft_move_down(t_game *player);
void ft_move_up(t_game *player);
 void ft_game(char **map);
void ft_move_right(t_game *player);
void ft_move_left(t_game *player);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
int		key_hook(int keycode, t_game *player);
char	*ft_itoa(int n);
void	ft_printf_map(char **map);
size_t	ft_strlen(const char *s);
int ft_height_of_map(char **map);
void find_enemy_p(t_game *player, char **map);
void find_player_p(t_game *player, char **map);
void ft_put_map_items(void *mlx, void *mlx_win, char **map, t_game *player);
int ft_collectible_count(char **map);
int ft_exit(void *str);
int animation(t_game *player);
int ft_loop_for_cheater(char **loop);
int ft_check_lines(char *str);
int ft_check_first_last_line(char *line);
int ft_border_of_map(char **map);
int ft_map_building(char **map);
void ft_check_map(char **map);
int ft_check_p_c_e(char **map);
int ft_collectible_count(char **map);
char *ft_make_matrix(int fd);
char *readi(int fd);
char    *ft_sstrjoin(char    *s1, char *c);
int ft_name_of_map(char *name);
int ft_height_of_map(char **map);
void p_and_next_e(int keycode, int *p_h, int *p_w, t_game *player);
void p_and_next_p(int keycode, int *p_h, int *p_w, t_game *player);
void find_player_p(t_game *player, char **map);
void ft_move_enemy(t_enemy *temp, t_game *player, int keycode);
void ft_move_enemys(t_game *player,int keycode);
void ft_move(t_game *player, int keycode);
void ft_print_moves(int x, t_game *player);
int	key_hook(int keycode, t_game *player);
void ft_put_map_items(void *mlx, void *mlx_win, char **map, t_game *player);
#endif