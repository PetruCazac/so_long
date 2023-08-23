/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:07:01 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 12:06:43 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief Checks the number of arguments
/// @param argc The input arguments
/// @return Returns if there is not 2 arguments
int	check_all(int argc)
{
	if (argc != 2)
	{
		perror("Wrong arguments!");
		exit(1);
	}
	return (EXIT_SUCCESS);
}
