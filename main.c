#include "./so_long.h"
/**
 * Prints error message and exits the program
 */
void	error_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

/**
 * Checks if the file has a .ber extension
 */
static int	check_file_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	return (ft_strncmp(dot, ".ber", 5) == 0);
}

/**
 * Program entry point
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(ERR_ARGS);
	if (!check_file_extension(argv[1]))
		error_exit("Error\nFile must have .ber extension");
	if (!init_game(&game, argv[1]))
		error_exit(ERR_MLX);
	mlx_loop(game.mlx);
	return (0);
}