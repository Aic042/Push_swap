/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:03:46 by root              #+#    #+#             */
/*   Updated: 2025/04/21 15:38:29 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!parse_argrs(argc, argv))
	{
		write(1, "Error with the parsing", 23);
		return 1;
	}
	return (0);
}