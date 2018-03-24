#include <iostream>
#include <fstream>

class assembler{

    std::string IP, OP;              // Input Path, Output Path
    char opcheck(std::string op);
    public :
            assembler(std::string a, std::string b);        // Initializes the file pointers and IP/OP
            void assembly();                                // Converts assembly instructions into hex values
};
