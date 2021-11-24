#include <iostream>
#include <cstdlib>

#include "Program.hpp"

Program::Program():programObject(glCreateProgram()){
        if(programObject==0){
                std::cerr << "glCreateProgram() Failed." << std::endl;
                std::exit(-1);
        }
}
