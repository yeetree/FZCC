#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
#include "utils.h"

std::string decompile(std::string file)
{
    std::string output;

    for(int i=0; i<file.length(); i++)
    {
        if(file[i] == '+')
        {
            if(file[i+1] == '+')
            {
                int ctr=1;
                while(file[i+1] == '+')
                {
                    ctr++;
                    i++;
                }
                output+="add," + std::to_string(ctr) + ";\n";
            }
            else
            {
                output+="add;\n";
            }
        }
        else if(file[i] == '-')
        {
            if(file[i+1] == '-')
            {
                int ctr=1;
                while(file[i+1] == '-')
                {
                    ctr++;
                    i++;
                }
                output+="sub," + std::to_string(ctr) + ";\n";
            }
            else
            {
                output+="sub;\n";
            }
        }
        if(file[i] == '<')
        {
            if(file[i+1] == '<')
            {
                int ctr=1;
                while(file[i+1] == '<')
                {
                    ctr++;
                    i++;
                }
                output+="left," + std::to_string(ctr) + ";\n";
            }
            else
            {
                output+="left;\n";
            }
        }
        else if(file[i] == '>')
        {
            if(file[i+1] == '>')
            {
                int ctr=1;
                while(file[i+1] == '>')
                {
                    ctr++;
                    i++;
                }
                output+="right," + std::to_string(ctr) + ";\n";
            }
            else
            {
                output+="right;\n";
            }
        }
        else if(file[i] == '.')
        {
            output+="out;\n";
        }
        else if(file[i] == ',')
        {
            output+="in;\n";
        }
        else if(file[i] == '[')
        {
            if(file[i+1] == '-' && file[i+2] == ']')
            {
                i+=2;
                if(file[i+1] == '+')
                {
                    int ctr=0;
                    while(file[i+1] == '+')
                    {
                        ctr++;
                        i++;
                    }
                    output+="set," + std::to_string(ctr) + ";\n";
                }
                else
                {
                    output+="set;\n";
                }
            }
            else
            {
                output+="loop;\n";
            }
        }
        else if(file[i] == ']')
        {
            output+="end;\n";
        }
    }

    return output;
}

int main(int argc, char* argv[])
{
    //see if we have enough command line arguments
    if (argc != 3)
    {
        std::cout << "BrainF**k to BrainFuzz Decompiler" << std::endl;
        std::cout << "Usage: bfd input.bf output.bfz" << std::endl;
        return 1;
    }

    try
    {
        //get file as string and compile it
        std::string file = inputFile(argv[1]);
        std::string output = decompile(file);

        //if compile didn't fail, print results.
        if(output != "-1")
        {
            writeFile(argv[2],output);
        }
        else
        {
            std::cout << "File did not decompile." << std::endl;
        }

    }
    catch (const std::exception& e)
    {
        std::cout << std::endl << e.what() << std::endl;
    }

    return 0;
}