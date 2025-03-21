/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwasakatsuya <iwasakatsuya@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:00:00 by player            #+#    #+#             */
/*   Updated: 2025/03/21 02:37:09 by iwasakatsuy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Helper function to load an XPM image
 */
static void	*load_xpm(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path, &game->img.width, 
			&game->img.height));
}

/**
 * Load all game images
 */
int	load_images(t_game *game)
{
	game->img.empty = load_xpm(game, "textures/empty.xpm");
	game->img.wall = load_xpm(game, "textures/wall.xpm");
	game->img.collectible = load_xpm(game, "textures/collectible.xpm");
	game->img.exit = load_xpm(game, "textures/exit.xpm");
	game->img.player = load_xpm(game, "textures/player.xpm");
	if (!game->img.empty || !game->img.wall || !game->img.collectible
		|| !game->img.exit || !game->img.player)
		return (0);
	return (1);
}

/**
 * Free all allocated memory
 */
static void	free_game(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
		{
			if (game->map.grid[i])
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	if (game->mlx)
	{
		if (game->img.empty)
			mlx_destroy_image(game->mlx, game->img.empty);
		if (game->img.wall)
			mlx_destroy_image(game->mlx, game->img.wall);
		if (game->img.collectible)
			mlx_destroy_image(game->mlx, game->img.collectible);
		if (game->img.exit)
			mlx_destroy_image(game->mlx, game->img.exit);
		if (game->img.player)
			mlx_destroy_image(game->mlx, game->img.player);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
	}
}

/**
 * Initialize game structure and components
 */
int	init_game(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!parse_map(game, map_file))
	{
		free_game(game);
		return (0);
	}
	validate_map(game);
	check_path(game);
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		free_game(game);
		return (0);
	}
	if (!load_images(game))
	{
		free_game(game);
		return (0);
	}
	mlx_hook(game->win, 2, 1L << 0, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	render_game(game);
	return (1);
}