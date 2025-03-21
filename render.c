#include "so_long.h"

/**
 * Render a specific tile on the window
 */
static void	render_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE,
		y * TILE_SIZE);
}

/**
 * Render the entire game map
 */
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