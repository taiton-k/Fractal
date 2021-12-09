#pragma once

#include <iostream>
#include <cstdlib>

#include <GL/glew.h>


class ShaderProgram{
        private:

        // 変数

        const GLuint programObject;


        // 関数

        GLboolean isProgramLinkedSuccessfully() const;

        GLvoid printProgramInfoLog() const;

        public:

        // 関数

        ShaderProgram();

        operator GLuint () const;

        GLvoid attachShader(const GLuint &shader) const;

        GLvoid link() const;
};
