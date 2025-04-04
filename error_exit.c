/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:19:05 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/31 00:40:20 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	error_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
