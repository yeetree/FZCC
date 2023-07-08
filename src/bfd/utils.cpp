#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <stack>
#include "utils.h"

std::string inputFile(const std::string& filename)
{
    std::string commands;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Failed to open '" + filename + "'.");

    while (file.good()) {
        commands.push_back(file.get());
    }

    return commands;
}

void writeFile(const std::string& filename, std::string content)
{
    std::ofstream file(filename);
    file << content;
    file.close();
    return;
}