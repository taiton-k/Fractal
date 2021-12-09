#pragma once

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>


#include <GL/glew.h>


class Shader{
        private:

        const GLuint shaderObject;

        GLenum shaderType() const;

        GLboolean isShaderCompiledSuccessfully() const;

        GLvoid printShaderInfoLog() const;

        GLvoid loadShaderSource(const char *fileName,char* &sourcePointer) const;


        public:

        Shader(const GLenum shaderType,const char *fileName);

        GLvoid changeSource(const char *fileName) const;

        operator GLuint() const;

};
