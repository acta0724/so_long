/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:28:34 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/30 02:38:32 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	free_map_finish(t_game *game)
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
}

void	free_mlx_resources(t_game *game)
{
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

void	free_game(t_game *game)
{
	free_map_finish(game);
	free_mlx_resources(game);
}
