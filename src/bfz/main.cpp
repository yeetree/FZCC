#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
#include "utils.h"

std::string compile(std::string file)
{
    //remove whitespace
    file.erase(std::remove_if(file.begin(), file.end(), ::isspace),
        file.end());

    //setup output
    std::string output = "";

    //get lines from file by comma
    std::vector<std::string> lines;
    tokenize(file, ';', lines);
    //get number of lines
    int lineslen = static_cast<int>(lines.size());

    int loopcounter=0;

    for(int i=0; i<lineslen; i++)
    {
        //get instruction from comma by line
        std::vector<std::string> inst;
        tokenize(lines[i], ',', inst);
        //get length of instruction
        int instlen = static_cast<int>(inst.size());
        //get first instsruction
        std::string finst = inst[0];

        //std::cout << finst << std::endl;

        if(finst == "!")
        {
            //Do nothing, it's a comment.
        }
        else if(finst == "left" || finst == "l")
        {
            if(instlen==1)
            {
                output+="<";
            }
            else if(instlen==2)
            {
                if(isNumber(inst[1]))
                {
                    output+=std::string(std::stoi(inst[1]),'<');
                }
                else if(inst[1].length() == 1)
                {
                    output+=std::string((int)inst[1][0],'<');
                }
                else
                {
                    output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Parameter is not a number." << std::endl;
                }
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "right" || finst == "r")
        {
            if(instlen==1)
            {
                output+=">";
            }
            else if(instlen==2)
            {
                if(isNumber(inst[1]))
                {
                    output+=std::string(std::stoi(inst[1]),'>');
                }
                else if(inst[1].length() == 1)
                {
                    output+=std::string((int)inst[1][0],'>');
                }
                else
                {
                    output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Parameter is not a number." << std::endl;
                }
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "add" || finst == "a")
        {
            if(instlen==1)
            {
                output+="+";
            }
            else if(instlen==2)
            {
                if(isNumber(inst[1]))
                {
                    output+=std::string(std::stoi(inst[1]),'+');
                }
                else if(inst[1].length() == 1)
                {
                    output+=std::string((int)inst[1][0],'+');
                }
                else
                {
                    output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Parameter is not a number." << std::endl;
                }
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "sub" || finst == "s")
        {
            if(instlen==1)
            {
                output+="-";
            }
            else if(instlen==2)
            {
                if(isNumber(inst[1]))
                {
                    output+=std::string(std::stoi(inst[1]),'-');
                }
                else if(inst[1].length() == 1)
                {
                    output+=std::string((int)inst[1][0],'-');
                }
                else
                {
                    output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Parameter is not a number." << std::endl;
                }
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "input" || finst == "in")
        {
            if(instlen==1)
            {
                output+=",";
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "output" || finst == "out")
        {
            if(instlen==1)
            {
                output+=".";
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "loop")
        {
            if(instlen==1)
            {
                output+="[";
                loopcounter+=1;
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
        else if(finst == "end")
        {
            if(instlen==1)
            {
                output+="]";
                loopcounter-=1;
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }

        else if(finst == "set")
        {
            if(instlen==1)
            {
                output+="[-]";
            }
            else if(instlen==2)
            {
                if(isNumber(inst[1]))
                {   
                    output+="[-]";
                    output+=std::string(std::stoi(inst[1]),'+');
                }
                else if(inst[1].length() == 1)
                {
                    output+="[-]";
                    output+=std::string((int)inst[1][0],'+');
                }
                else
                {
                    output = "-1";
                    std::cout << "Error at line " << std::to_string(i + 1) << ": Parameter is not a number." << std::endl;
                }
            }
            else
            {
                output = "-1";
                std::cout << "Error at line " << std::to_string(i + 1) << ": Invalid amount of arguments." << std::endl;
            }
        }
    }

    //see if we have any unmatched loops
    if(loopcounter!=0)
    {
        output = "-1";
        std::cout << "Error: Unclosed loops." << std::endl;
    }

    return output;
}

int main(int argc, char* argv[])
{
    //see if we have enough command line arguments
    if (argc != 3)
    {
        std::cout << "BrainFuzz to BrainF**k Compiler" << std::endl;
        std::cout << "Usage: bfz input.bfz output.bf" << std::endl;
        return 1;
    }

    try
    {
        //get file as string and compile it
        std::string file = inputFile(argv[1]);
        std::string output = compile(file);

        //if compile didn't fail, print results.
        if(output != "-1")
        {
            writeFile(argv[2],output);
        }
        else
        {
            std::cout << "File did not compile." << std::endl;
        }

    }
    catch (const std::exception& e)
    {
        std::cout << std::endl << e.what() << std::endl;
    }

    return 0;
}