/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:04:54 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/24 23:06:46 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string unescapeSequences(const std::string &str) {
    std::string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\\' && i + 1 < str.length()) {
            if (str[i + 1] == 'n') {
                result += '\n';
                ++i;
            } else if (str[i + 1] == 't') {
                result += '\t';
                ++i;
            } else {
                result += str[i];
            }
        } else {
            result += str[i];
        }
    }
    return result;
}

void replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream infile(filename.c_str());
    std::ofstream outfile((filename + ".replace").c_str());
    std::string line;
    std::string::size_type pos;

    if (!infile)
    {
        std::cerr << "Couldn't open file for reading." << std::endl;
        return;
    }

    char c;
    std::string buffer;
    while (infile.get(c))
    {
        buffer += c;
    }

    for (std::string::size_type i = 0; i < buffer.length(); )
    {
        pos = buffer.find(s1, i);
        if (pos != std::string::npos)
        {
            outfile << buffer.substr(i, pos - i) << s2;
            i = pos + s1.length();
        }
        else
        {
            outfile << buffer.substr(i);
            break;
        }
    }

    infile.close();
    outfile.close();
}

bool validateArguments(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        std::cerr << "Usage: ./sed filename s1 s2" << std::endl;
        return (1);
    }
    
    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cerr << "Couldn't open file." << std::endl;
        std::cerr << "Either bad permissions or file does not exist." << std::endl;
        return (1);
    }
    
    if (std::string(argv[2]).empty())
    {
        std::cerr << "Empty string (s1) is not allowed." << std::endl;
        return (1);
    }
    
    return (0);
}

int main(int argc, char **argv) 
{
    if (validateArguments(argc, argv))
    {
        std::cout << "Arguments are not valid." << std::endl;
        return (1);
    }

    std::cout << "File opened successfully." << std::endl;

    std::string s1 = unescapeSequences(argv[2]);
    std::string s2 = unescapeSequences(argv[3]);

    replace(argv[1], s1, s2);
    return (0);
}
