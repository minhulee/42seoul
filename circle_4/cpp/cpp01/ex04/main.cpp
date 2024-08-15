/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:56:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/08 15:30:39 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <iostream>
# include <fstream>

std::ifstream	*OpenIfstream(const std::string &file)
{

}

std::string	&ft_replace(std::ifstream &inFile, const std::string &from, const std::string &to, std::ofstream &outFile)
{
	std::string	buffer;
	int			i;

	while (std::getline(inFile, buffer))
	{
		i = 0;
		while ((i = buffer.find(from, i)) != std::string::npos)
		{
			buffer.erase(i, from.length());
			buffer.insert(i, to);
			i += to.length();
		}
		outFile << buffer << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::string		res;
	int				i;

	if (argc != 4)
	{
		std::cout << "Invalid argv...\n" << std::endl;
		return (1);
	}
	else
	{
		std::ifstream inFile(argv[1]);
		if (!inFile)
		{
			std::cerr << "Can't read file\n" << std::endl;
			return (1);
		}
		std::ofstream outFile(std::string(argv[1]).append(".replace"));
		if (!outFile)
		{
			std::cerr << "Can't open file\n" << std::endl;
			return (1);
		}
		ft_replace(inFile, std::string(argv[2]), std::string(argv[3]), outFile);
		inFile.close();
		outFile.close();
	}
}