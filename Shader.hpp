#pragma once

#include <GL/glew.h>


class Shader{
        private:

        const GLuint shaderObject;

        GLenum getShaderType() const;


        public:

        Shader(GLenum shaderType);

};
