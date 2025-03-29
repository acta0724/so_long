/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:51 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/30 02:14:53 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	render_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE,
		y * TILE_SIZE);
}

void	render_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			render_tile(game, game->img.empty, j, i);
			if (game->map.grid[i][j] == WALL)
				render_tile(game, game->img.wall, j, i);
			else if (game->map.grid[i][j] == COLLECTIBLE)
				render_tile(game, game->img.collectible, j, i);
			else if (game->map.grid[i][j] == EXIT)
				render_tile(game, game->img.exit, j, i);
			j++;
		}
		i++;
	}
	render_tile(game, game->img.player, game->map.player.x, game->map.player.y);
}
