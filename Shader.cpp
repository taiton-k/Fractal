#include <iostream>
#include <cstdlib>

#include "Shader.hpp"


Shader::Shader(GLenum shaderType):shaderObject(glCreateShader(shaderType)){
        if(shaderObject==0){
                std::cerr << "glCreateShader() Failed." << std::endl;
        }
}


GLenum Shader::getShaderType() const{
        GLint params=0;
        glGetShaderiv(shaderObject,GL_SHADER_TYPE,&params);
        return static_cast<GLenum>(params);
}
