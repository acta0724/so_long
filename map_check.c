/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:37 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/28 23:02:58 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] != EMPTY 
					&& game->map.grid[i][j] != WALL
					&& game->map.grid[i][j] != COLLECTIBLE
					&& game->map.grid[i][j] != EXIT 
					&& game->map.grid[i][j] != PLAYER)
			{
				error_exit(ERR_CHARS);
			}
			j++;
		}
		i++;
	}
}

void	check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if ((int)ft_strlen(game->map.grid[i]) != game->map.width)
			error_exit(ERR_RECT);
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((i == 0 || i == game->map.height - 1 || j == 0
					|| j == game->map.width - 1) && game->map.grid[i][j] != WALL)
				error_exit(ERR_WALL);
			j++;
		}
		i++;
	}
}

void	check_components(t_game *game)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	game->map.collectibles = 0;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] == PLAYER)
			{
				game->map.player.x = j;
				game->map.player.y = i;
				player_count++;
			}
			else if (game->map.grid[i][j] == EXIT)
			{
				game->map.exit.x = j;
				game->map.exit.y = i;
				exit_count++;
			}
			else if (game->map.grid[i][j] == COLLECTIBLE)
				game->map.collectibles++;
		}
	}
	if (player_count != 1)
		error_exit(ERR_PLAYER);
	if (exit_count != 1)
		error_exit(ERR_EXIT);
	if (game->map.collectibles < 1)
		error_exit(ERR_COLLECT);
}
