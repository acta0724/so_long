/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:54 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/30 02:39:53 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/libft.h"

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define TILE_SIZE 32
# define BUFFER_SIZE 42

# define ERR_EXTENSION "Error\nFile must have .ber extension"
# define ERR_ARGS "Error\nInvalid arguments. Usage: ./so_long <map.ber>"
# define ERR_FILE "Error\nCannot open map file"
# define ERR_MAP "Error\nInvalid map"
# define ERR_RECT "Error\nMap is not rectangular"
# define ERR_WALL "Error\nMap is not enclosed by walls"
# define ERR_CHARS "Error\nMap contains invalid characters"
# define ERR_PLAYER "Error\nInvalid number of players (must be 1)"
# define ERR_EXIT "Error\nInvalid number of exits (must be 1)"
# define ERR_COLLECT "Error\nNo collectibles found"
# define ERR_PATH "Error\nNo valid path to exit and collectibles"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MEM "Error\nMemory allocation failed"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		collectibles_found;
	int		exit_found;
	t_pos	player;
	t_pos	exit;
}	t_map;

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		moves;
	int		collected;
}	t_game;

void	error_exit(char *message);

int		init_game(t_game *game, char *map_file);
int		load_images(t_game *game);

int		parse_map(t_game *game, char *map_file);
void	validate_map(t_game *game);

void	check_chars(t_game *game);
void	check_rectangular(t_game *game);
void	check_walls(t_game *game);
void	check_components(t_game *game);

void	check_path(t_game *game);
void	flood_fill(t_game *game, char **visited, int x, int y);

void	render_game(t_game *game);

int		key_handler(int keycode, t_game *game);
int		close_window(t_game *game);

int		move_player(t_game *game, int new_x, int new_y);

int		is_valid_move(t_game *game, int x, int y);
int		check_win(t_game *game);
char	**copy_map(char **map, int height);
void	free_map(char **map, int height);

char	*get_next_line(int fd);
void	free_game(t_game *game);
void	free_map_finish(t_game *game);
void	free_mlx_resources(t_game *game);

#endif