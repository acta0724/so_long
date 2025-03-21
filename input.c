#include "so_long.h"

/**
 * Handle window close event
 */
int	close_window(t_game *game)
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
	exit(0);
	return (0);
}

/**
 * Handle keyboard input
 */
int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->map.player.x, game->map.player.y - 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->map.player.x - 1, game->map.player.y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->map.player.x, game->map.player.y + 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->map.player.x + 1, game->map.player.y);
	return (0);
}