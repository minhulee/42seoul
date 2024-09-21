/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:56:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 17:03:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

void	ft_replace(std::ifstream &inFile, const std::string &from, const std::string &to, std::ofstream &outFile)
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
		exit(1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cout << "s1 is empty\n" << std::endl;
		exit(1);
	}
	std::ifstream	inFile(argv[1]);
	if (!inFile)
	{
		std::cerr << "Can't read file\n" << std::endl;
		exit(1);
	}
	std::ofstream	outFile(std::string(argv[1]).append(".replace"));
	if (!outFile)
	{
		std::cerr << "Can't open file\n" << std::endl;
		exit(1);
	}
	ft_replace(inFile, std::string(argv[2]), std::string(argv[3]), outFile);
	inFile.close();
	outFile.close();
}