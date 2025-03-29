/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:28 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/30 01:25:06 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	check_file_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	return (ft_strncmp(dot, ".ber", 5) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(ERR_ARGS);
	if (!check_file_extension(argv[1]))
		error_exit(ERR_EXTENSION);
	if (!init_game(&game, argv[1]))
		error_exit(ERR_MLX);
	mlx_hook(game.win, 2, 1L << 0, key_handler, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
