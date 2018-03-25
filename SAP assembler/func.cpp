#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "assembler.cpp"
#define rsize 32

assembler::assembler(std::string a, std::string b)
{
    IP = a;
    OP = b;
}
 int assembler::getval(std::string value)
 {
     int n = value.length(), val = 0, i=0;
     while(n--)
     {
        val += pow(10, n)*(value[i] - '0');
        ++i;
        }
    if(255 >= val >= 0)
        return val;
    else
        return -1;
 }
 char assembler::getaddress(std::string ad)
 {
     if(ad[0] == '0' && ad[1] == 'x')
     {
         if(isdigit(ad[2]) && '1' < ad[2] < '15')
            return ad[2];
         else
         {
             std::cout<<"Erroneous address";
             return -1;
         }
     }
     else
    {
        std::cout<<"Erroneous address";
        return -1;
    }
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
              {
                code[linecount] = opcheck(line.substr(0, 3));
                if(code[linecount] != 'f' && code[linecount] != 'd' && code[linecount] != '9')
                /*
                 instruction address value
                */
                {
                    char addr = getaddress(line.substr(4, 7));
                    //std::cout<<addr<<"\n";
                    code[linecount+1] = addr;
                    if(addr == -1)
                        break;
                    else
                    /*
                    Extracting value
                    */
                    {

                        int val = getval(line.substr(9, line.length()));
                        if(val != -1)
                        {
                            std::stringstream sstream;
                            sstream << std::hex << val;
                            std::string result = sstream.str();
                            code[2*(int(addr - '0'))] = result[0];
                            code[2*int(addr - '0') + 1] = result[1];

                        }
                        else
                        {
                            std::cout<<"Erroneous integer value";
                            break;
                        }
                    }
                }
              }
            else
                break;
            linecount += 2;
        }
        std::cout<<"\n"<<code;

}


 int main()
 {
     // aprogram.txt
     std::string p;
     std::cout<<"Enter the Input file name\n";
     std::cin>>p;
     std::cout<<"Assembly level code for the program ";
     assembler a( p, "sddfd.txt");
     a.assembly();
     std::string ch;
     std::cout<<"\nPress any key to exit";
     std::cin>>ch;
     exit(65);
     return 0;
 }
