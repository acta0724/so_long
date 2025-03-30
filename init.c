/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:00:00 by player            #+#    #+#             */
/*   Updated: 2025/03/31 00:00:46 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	*load_xpm(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path,
			&game->img.width, &game->img.height));
}

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
	render_game(game);
	return (1);
}
