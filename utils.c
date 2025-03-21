#include "so_long.h"

/**
 * Check if a move is valid
 */
int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == WALL)
		return (0);
	return (1);
}

/**
 * Check if the game is won
 */
int	check_win(t_game *game)
{
	if (game->map.player.x == game->map.exit.x
		&& game->map.player.y == game->map.exit.y
		&& game->collected == game->map.collectibles)
		return (1);
	return (0);
}

/**
 * Free map memory
 */
void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

/**
 * Create a copy of the map
 */
char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}