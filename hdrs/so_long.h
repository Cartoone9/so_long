/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:54:19 by *******           #+#    #+#             */
/*   Updated: 2025/02/22 16:19:36 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

// cell size
# define CS 32

// keys codes
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define KEY_W 119
# define KEY_Z 122
# define KEY_A 97
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100

# define ESC 65307

// delays
# define ANIMATION_DELAY 60000
# define WINLOSE_DELAY 500000
# define FADE_DELAY 7500
# define LATENCY 15

// exit sprites
# define PATH_CHEST_1 "sprites/exit/chest_1.xpm"
# define PATH_CHEST_2 "sprites/exit/chest_2.xpm"
# define PATH_CHEST_3 "sprites/exit/chest_3.xpm"
# define PATH_CHEST_4 "sprites/exit/chest_4.xpm"
# define PATH_CHEST_LOCK "sprites/exit/chest_lock.xpm"

// key sprites
# define PATH_KEY_1 "sprites/collect/key_1.xpm"
# define PATH_KEY_2 "sprites/collect/key_2.xpm"
# define PATH_KEY_3 "sprites/collect/key_3.xpm"
# define PATH_KEY_4 "sprites/collect/key_4.xpm"

// player sprites
# define PATH_PLAYER_1 "sprites/player/player_1.xpm"
# define PATH_PLAYER_2 "sprites/player/player_2.xpm"
# define PATH_PLAYER_3 "sprites/player/player_3.xpm"
# define PATH_PLAYER_4 "sprites/player/player_4.xpm"

// enemy sprites
# define PATH_ENEMY_1 "sprites/enemy/enemy_1.xpm"
# define PATH_ENEMY_2 "sprites/enemy/enemy_2.xpm"
# define PATH_ENEMY_3 "sprites/enemy/enemy_3.xpm"
# define PATH_ENEMY_4 "sprites/enemy/enemy_4.xpm"

// background sprites
# define PATH_TILE_TOP "sprites/background/tile_top.xpm"
# define PATH_TILE_BOT "sprites/background/tile_bot.xpm"
# define PATH_TILE_LEFT "sprites/background/tile_left.xpm"
# define PATH_TILE_RIGHT "sprites/background/tile_right.xpm"
# define PATH_TILE_TOP_LEFT "sprites/background/tile_top_left.xpm"
# define PATH_TILE_TOP_RIGHT "sprites/background/tile_top_right.xpm"
# define PATH_TILE_BOT_LEFT "sprites/background/tile_bot_left.xpm"
# define PATH_TILE_BOT_RIGHT "sprites/background/tile_bot_right.xpm"

# define PATH_TILE_WALL "sprites/background/tile_wall.xpm"
# define PATH_TILE_GROUND "sprites/background/tile_ground.xpm"
# define PATH_TILE_WHITE "sprites/background/tile_white.xpm"
# define PATH_TILE_BLACK "sprites/background/tile_black.xpm"

// ending sprites
# define PATH_GG_0 "sprites/gg/gg_0.xpm"
# define PATH_GG_1 "sprites/gg/gg_1.xpm"
# define PATH_GG_2 "sprites/gg/gg_2.xpm"
# define PATH_GG_3 "sprites/gg/gg_3.xpm"
# define PATH_GG_4 "sprites/gg/gg_4.xpm"
# define PATH_GG_5 "sprites/gg/gg_5.xpm"
# define PATH_GG_6 "sprites/gg/gg_6.xpm"
# define PATH_GG_7 "sprites/gg/gg_7.xpm"
# define PATH_GG_8 "sprites/gg/gg_8.xpm"
# define PATH_GG_9 "sprites/gg/gg_9.xpm"
# define PATH_GG_10 "sprites/gg/gg_10.xpm"
# define PATH_GG_11 "sprites/gg/gg_11.xpm"
# define PATH_GG_12 "sprites/gg/gg_12.xpm"

# define PATH_LOSE_0 "sprites/gg/lose_0.xpm"
# define PATH_LOSE_1 "sprites/gg/lose_1.xpm"
# define PATH_WIN_0 "sprites/gg/win_0.xpm"
# define PATH_WIN_1 "sprites/gg/win_1.xpm"
# define PATH_GAME_OVER "sprites/gg/game_over.xpm"

typedef struct s_pos
{
	int			p[2];
	int			e[2];
}				t_pos;

typedef struct s_image
{
	void		*main;
	void		*temp_a;
	void		*temp_b;
	char		*addr_m;
	char		*addr_t;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_map
{
	char		**main;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct s_game
{
	size_t		available;
	size_t		collected;
	size_t		enemy;
	size_t		moves;
}				t_game;

typedef struct s_sprite
{
	void		*tile_t;
	void		*tile_b;
	void		*tile_l;
	void		*tile_r;
	void		*tile_tl;
	void		*tile_tr;
	void		*tile_bl;
	void		*tile_br;
	void		*tile_grnd;
	void		*tile_wall;
	void		*tile_white;
	void		*tile_black;
	void		*key_1;
	void		*key_2;
	void		*key_3;
	void		*key_4;
	void		*player_1;
	void		*player_2;
	void		*player_3;
	void		*player_4;
	void		*enemy_1;
	void		*enemy_2;
	void		*enemy_3;
	void		*enemy_4;
	void		*chest_lock;
	void		*chest_1;
	void		*chest_2;
	void		*chest_3;
	void		*chest_4;
	void		*game_over;
	void		*win_0;
	void		*win_1;
	void		*lose_0;
	void		*lose_1;
	void		*gg_0;
	void		*gg_1;
	void		*gg_2;
	void		*gg_3;
	void		*gg_4;
	void		*gg_5;
	void		*gg_6;
	void		*gg_7;
	void		*gg_8;
	void		*gg_9;
	void		*gg_10;
	void		*gg_11;
	void		*gg_12;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_sprite;

typedef struct s_data
{
	void		*server;
	void		*win;
	t_game		*game;
	t_image		*img;
	t_sprite	*sprite;
	t_map		*map;
	t_pos		*pos;
	int			end;
	int			winner;
	int			loser;
	int			easter;
}				t_data;

typedef struct s_elem
{
	size_t		collect;
	size_t		player;
	size_t		enemy;
	size_t		exit;
}				t_elem;

typedef struct s_cursor
{
	size_t		row;
	size_t		col;
}				t_cursor;

size_t			ft_strlen(const char *str);
size_t			ft_strrlen(char **strr);
size_t			ft_strcnt(const char *str, char c);
size_t			ft_nextch(const char *str, char c);
char			**ft_copy_map(char **map);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
char			*ft_strjoin_keys(char const *s1, char const *s2,
					char const *s3);
char			*ft_itoa(int n);
void			ft_init_elem_csr(t_elem *elem, t_cursor *csr);
void			ft_error(char *error_msg);
void			ft_free_str(char *str);
void			ft_free_strr(char **strr);
void			ft_infect_map(char **map, int pos[2], size_t *collected);
void			ft_infect_top(char **map, int pos[2], size_t *collected);
void			ft_infect_right(char **map, int pos[2], size_t *collected);
void			ft_infect_bot(char **map, int pos[2], size_t *collected);
void			ft_infect_left(char **map, int pos[2], size_t *collected);
void			ft_update_elem(t_cursor *csr, t_elem *elem, t_pos *pos,
					int which);
void			ft_move_player(t_data *data, int y, int x, int which);
void			ft_cpy_background(t_data *data);
void			ft_paste_sprite(t_data *data, size_t x, size_t y, int which);
void			ft_null_init(t_data *data);
void			ft_free_data(t_data *data);
void			ft_free_data_suite(t_data *data);
void			ft_rm_pixel(t_data *data);
void			ft_init_sprite(t_data *data);
void			*ft_which_gg(t_data *data, size_t i);
void			*ft_which_key(t_data *data);
void			*ft_which_player_exit(t_data *data, int which);
void			*ft_which_enemy(t_data *data);
void			*ft_which_loser(t_data *data);
void			*ft_render_elements_newimg(t_data *data, int *which);
void			*ft_which_background(t_data *data, int which);
void			*ft_which_exit(t_data *data, size_t i);
void			*ft_render_elements_whichimg_a(t_data *data, int *which);
void			*ft_render_elements_whichimg_b(t_data *data, int *which);
void			ft_move_player_utils(t_data *data, int y, int x, int which);
void			ft_end_game_winner(t_data *data);
void			ft_end_game_loser(t_data *data);
void			ft_end_game_img(t_data *data);
void			ft_free_image_1(t_data *data);
void			ft_free_sprite_1(t_data *data);
void			ft_free_sprite_2(t_data *data);
void			ft_free_sprite_3(t_data *data);
void			ft_free_sprite_4(t_data *data);
void			ft_middle_row_update(char c, t_elem *elem, t_pos *pos,
					t_cursor *csr);
void			ft_update_data_map(t_data *data, size_t j, size_t k);
void			ft_init_sprite_2(t_data *data);
void			ft_init_sprite_3(t_data *data);
void			*ft_choose_sprite(t_data *data, int which);
int				ft_key_id(int key_code);
int				ft_which_sprite(t_data *data, size_t x, size_t y, int which);
int				ft_split(char const *s, char c, t_data *data);
int				ft_store_map(t_data *data, int fd);
int				ft_open_file(char *file_name);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_check_map(t_data *data, char **map);
int				ft_topnbot_row(char **map, size_t row, size_t *col);
int				ft_middle_row(char **map, t_elem *elem, t_pos *pos,
					t_cursor *csr);
int				ft_check_elem(char **map, t_elem elem, t_pos pos, t_data *data);
int				ft_check_exit(char **map, int exit_pos[2]);
int				ft_run_game(t_data *data);
int				ft_init_game_info(t_data *data);
int				ft_init_data(t_data *data);
int				ft_key_press(int key_code, void *vdata);
int				ft_close_window(t_data *data);
int				ft_init_image(t_data *data);
int				ft_render_background(t_data *data);
int				ft_check_sprites(void);
int				ft_render_elements(t_data *data);
int				ft_init_pos(t_data *data);
int				ft_display_score(t_data *data);
int				ft_display_keys(t_data *data);
int				ft_end_game(void *vdata);
int				ft_set_colors(size_t i);
int				ft_load_sprites(t_data *data);
int				ft_load_sprites_player(t_data *data, int *width, int *height);
int				ft_load_sprites_background(t_data *data, int *width,
					int *height);
int				ft_load_sprites_background_suite(t_data *data, int *width,
					int *height);
int				ft_load_sprites_gg(t_data *data, int *width, int *height);
int				ft_load_sprites_collect(t_data *data, int *width, int *height);
int				ft_load_sprites_exit(t_data *data, int *width, int *height);
int				ft_load_sprites_enemy(t_data *data, int *width, int *height);
int				ft_middle_wall(t_data *data, size_t y, size_t x);
int				ft_topbot_wall(t_data *data, size_t y, size_t x);
int				ft_add_topline(char **strr, char const *s, char c);
int				ft_add_botline(char **strr, char const *s, char c, int j);
int				ft_game_latency(t_data *data);
int				ft_black_fade(t_data *data);
int				ft_render_background_loop(t_data *data, size_t x, size_t y);
int				ft_render_elements_onbackg(t_data *data);
int				ft_put_img_n_hud(t_data *data, size_t which);
int				ft_render_elements_onbackg_loop(t_data *data, size_t x,
					size_t y);
int				ft_load_sprites_gg_1(t_data *data, int *width, int *height);
int				ft_load_sprites_gg_2(t_data *data, int *width, int *height);
int				ft_load_sprites_gg_3(t_data *data, int *width, int *height);
int				ft_load_sprites_gg_4(t_data *data, int *width, int *height);
int				ft_check_empty(const char *s, char c);

# define FADE_TEXT "__________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________\
______________________________________________________________________"
#endif
