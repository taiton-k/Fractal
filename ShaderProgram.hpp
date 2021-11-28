#pragma once

#include <iostream>
#include <cstdlib>

#include <GL/glew.h>


class ShaderProgram{
        private:

        // 変数

        const GLuint programObject;


        // 関数

        inline GLboolean isProgramLinkedSuccessfully() const;

        inline GLvoid printProgramInfoLog() const;

        public:

        // 関数

        ShaderProgram();

        inline GLvoid attachShader(const GLuint &shader) const;

        GLvoid linkProgramObject() const;
};
