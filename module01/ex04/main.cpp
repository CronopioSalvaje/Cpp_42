/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/13 10:07:57 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>



int getNumberOfLines(std::string path)
{
   int i = 0;
   std::ifstream file(path.c_str());
   std::string line;
   if (!file.is_open())
   {
      std::cerr << "invalid file" << std::endl;
      return -1;
   }
   ;
   while (std::getline(file, line))
      i++;
   file.close();
   if (i == 0)
   {
      std::cerr << "file is empty" << std::endl;
      return -1;
   }
   return i;
}

int readLines(std::string *lines, std::string path)
{
   int i = 0;
   std::ifstream file(path.c_str());
   std::string line;
   if (!file.is_open())
   {
      std::cerr << "invalid file" << std::endl;
      return -1;
   }
   while (std::getline(file, line))
   {
      lines[i] = line;
      i++;
   }
   file.close();
   return 0;
}

void printlines(std::string *lines, int nblines)
{
   int i = 0;
   while (i < nblines)
   {
      std::cout << lines[i] << std::endl;
      i++;
   }
}

bool isNext(std::string line, std::string oldStr)
{
   return line.find(oldStr) != std::string::npos;
}

std::string getnewline(std::string line, std::string oldStr, std::string newStr)
{
   int in = 0;
   std::string newline;
   
   while (isNext(line, oldStr))
   {
      in++;
      newline += line.substr(0, line.find(oldStr)) + newStr;
      line = line.substr (line.find(oldStr) + oldStr.size(), std::string::npos);
      if (!isNext(line,oldStr))
         newline += line;      
   }
   if (!in)
      return line;
   return newline;   
}

int replaceSeq(std::string *lines, std::string oldStr, std::string newStr, std::string replace, int nblines)
{
   int i = 0;
   
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




int main(int ac, char **av)
{
   if (ac != 4)
   {
      std::cout << "Invalid args, please enter a filename, string_to_replace, new_string" << std:: endl;
      return (1);      
   }
   std::string path(av[1]);
   std::string replace = (path + ".replace");
   std::string oldStr(av[2]);
   std::string newStr(av[3]);

   int nbLines = getNumberOfLines(path);
   if (nbLines < 1)
      return (1);
   std::string lines[nbLines];
   if (readLines(lines, path) == -1)
      return (1);
   if (replaceSeq(lines, oldStr, newStr, replace, nbLines) == -1)
      return (1);
   return 0;
}
