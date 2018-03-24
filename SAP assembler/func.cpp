#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "assembler.cpp"
#define rsize 32

assembler::assembler(std::string a, std::string b)
{
    IP = a;
    OP = b;
}
 char assembler::opcheck(std::string op)
 {
    if(op == "lda")
        return '0';
    else if(op == "add")
        return 'b';
    else if(op == "sub")
        return 'c';
    else if(op == "hlt")
        return 'f';
    else if(op == "sta")
        return '1';
    else if(op == "orr")
        return 'a';
    else if(op == "not")
        return '9';
    else if(op == "and")
        return '8';
    else if(op == "out")
        return 'd';
    else
    {
        std::cout<<"Undefined instruction";
        return '-1';
     }
 }
void assembler::assembly()
{
    std::string code(rsize, '0');
    std::string line;
    int linecount = 0;
    std::ifstream p1(IP);
        while(std::getline(p1, line))
        {
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            if(opcheck(line.substr(0, 3)) != -1 )
                code[linecount] = opcheck(line.substr(0, 3));
            else
                break;
            linecount += 2;
        }
        std::cout<<"\n"<<code;

}


 int main()
 {
     assembler a("aprogram.txt", "sddfd.txt");
     a.assembly();
    return 0;
 }
