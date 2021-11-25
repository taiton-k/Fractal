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

        GLenum getShaderType() const;

        static GLchar **loadShaderSource(const char *fileName);

        inline GLboolean isShaderCompiledSuccessfully() const;

        inline GLvoid printShaderInfoLog() const;


        public:

        Shader(GLenum shaderType,const char *fileName);

        operator GLuint() const;

};
