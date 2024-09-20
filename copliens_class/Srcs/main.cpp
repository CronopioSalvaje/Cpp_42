/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 17:47:01 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>


int	getNumberOfLines(std::string path)
{
	int	i;

	i = 0;
	std::ifstream file(path.c_str());
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "invalid file : " << path << std::endl;
		return (-1);
	};
	while (std::getline(file, line))
		i++;
	file.close();
	if (i == 0)
	{
		std::cerr << "file is empty" << std::endl;
		return (-1);
	}
	return (i);
}

int	readLines(std::string *lines, std::string path)
{
	int	i;

	i = 0;
	std::ifstream file(path.c_str());
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "invalid file : " << path << std::endl;
		return (-1);
	}
	while (std::getline(file, line))
	{
		lines[i] = line;
		i++;
	}
	file.close();
	return (0);
}

void	printlines(std::string *lines, int nblines)
{
	int	i;

	i = 0;
	while (i < nblines)
	{
		std::cout << lines[i] << std::endl;
		i++;
	}
}

bool	isNext(std::string line, std::string oldStr)
{
	return (line.find(oldStr) != std::string::npos);
}

std::string getnewline(std::string line, std::string oldStr, std::string newStr)
{
	int	in;

	in = 0;
	std::string newline;
	while (isNext(line, oldStr))
	{
		in++;
		newline += line.substr(0, line.find(oldStr)) + newStr;
		line = line.substr(line.find(oldStr) + oldStr.size(),
				std::string::npos);
		if (!isNext(line, oldStr))
			newline += line;
	}
	if (!in)
		return (line);
	return (newline);
}

int	replaceSeq(std::string *lines, std::string oldStr, std::string newStr,
		std::string replace, int nblines)
{
	int	i;

	i = 0;
	std::ofstream outfile(replace.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "something went wrong creating output file" << std::endl;
		return (-1);
	}
	while (i < nblines)
	{
		outfile << getnewline(lines[i], oldStr, newStr) << std::endl;
		i++;
	}
	outfile.close();
	return (0);
}

std::string getPwd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		std::string tmp(env[i]);
		/*if (tmp.find("OLDPWD=") != std::string::npos)
			continue;*/
		if (tmp.find("PWD=") != std::string::npos && tmp.find("OLDPWD=") == std::string::npos )
			return (tmp.substr(4, std::string::npos) + "/");
		i++;
	}
	return ("./");
}

std::string getKey(char **env, std::string key)
{
	int	i;

	i = 0;
	while (env[i])
	{
		std::string tmp(env[i]);
		/*if (tmp.find("OLDPWD=") != std::string::npos)
			continue;*/
		if (tmp.find(key) != std::string::npos)
			return (tmp.substr(key.length(), std::string::npos) + "/");
		i++;
	}
	return ("./");
}

int formatClassName(char *className)
{
	if (isdigit(className[0]))
		return -1;
	int i = 0;
	while (className[i])
	{
		if (!isalnum(className[i]))
			return -1;
		if (i == 0)
			className[i] = toupper(className[i]);
		else
			className[i] = tolower(className[i]);
		i++;
	}
	return (0);
}

std::string uppercase(std::string str)
{
	int i = 0;
	char *old = (char *) str.c_str();
	while (old[i])
	{
		old[i] = toupper(old[i]);
		i++;
	}
	std::string newStr(old);
	return newStr;
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int j = 0;
	int	nbLines;

	std::string paths[2] = { getKey(env, "HOME=") + "/bin/coplien/templates/template.hpt",
		getKey(env, "HOME=") + "/bin/coplien/templates/template.cpt"};
	if (ac < 1)
	{
		std::cout << "Must have at least one class name" << std::endl;
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		if (formatClassName(av[i]) == -1)
		{
			std::cout << "invalid class name format" << std::endl;
			i++;
			continue;
		}
		std::string newStr(av[i]);
		std::string replace[2];
		replace[0] = getPwd(env) + newStr + ".hpp";
		replace[1] = getPwd(env) + newStr + ".cpp";
		std::cout << replace[0] << "  " << replace[1] << std::endl;
		while (j < 2)
		{
			nbLines = getNumberOfLines(paths[j]);
			if (nbLines < 1)
				return (1);
			std::string lines[nbLines];
			if (readLines(lines, paths[j]) == -1)
				return (1);
			if (replaceSeq(lines, "template", newStr, "class.temp", nbLines) == -1)
				return (1);
			std::string replacedLines[nbLines];
			if (readLines(replacedLines, "class.temp") == -1)
				return (1);
			if (replaceSeq(replacedLines, "TEMPLATE", uppercase(newStr), replace[j], nbLines) == -1)
				return (1);

			j++;
		}
		remove("class.temp");
		j = 0;
		i++;
	}

	return (0);
}
