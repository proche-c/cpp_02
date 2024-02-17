/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void	harlSwitch(std::string level, Harl &aHarl)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			complainLevel = -1;
	int	i = 0;

	while (i < 4)
	{
		if (levels[i] == level)
		{
			complainLevel = i;
			break ;
		}
		i++;
	}
	switch (complainLevel)
	{
		case 0:
			aHarl.complain("DEBUG");
		case 1:
			aHarl.complain("INFO");
		case 2:
			aHarl.complain("WARNING");
		case 3:
			aHarl.complain("ERROR");
			break;
		default:
			std::cout << "Wtf are you complaining about?" << std::endl;
	}

}

int	main(int argc, char **argv)
{
	Harl	SuperHarl;

	if (argc == 2)
		harlSwitch(argv[1], SuperHarl);
	else
		std::cout << "That's not even a level of complaint" << std::endl;

	return (0);
}