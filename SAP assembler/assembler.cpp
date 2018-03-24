#include <iostream>
#include <fstream>

class assembler{

    std::string IP, OP;              // Input Path, Output Path
    std::ifstream iPtr;              // Input File Pointer,
    std::ofstream oPtr;              // Output File Pointer
    public :
            assembler(std::string a, std::string b);        // Initializes the file pointers and IP/OP
            ~assembler();                                   // Closes the file opened by file pointers
            void assembly();                                // Converts assembly instructions into hex values
};
