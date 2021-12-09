#include "Utils.hpp"

void initializeGLFW(){
        if(glfwInit() == GLFW_FALSE){
                std::cerr << "Failed to initializing GLFW." << std::endl; 
                std::exit(-1);
        }
        return;
}

void initializeGLEW(){
        glewExperimental = GL_TRUE;
        if(glewInit()!=GLEW_OK){
                std::cout << "Failed to initializing GLEW.";
                std::exit(-1);
        }
}

