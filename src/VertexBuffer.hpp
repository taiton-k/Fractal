#pragma once

#include <GL/glew.h>


class VertexBuffer{
        private:

        GLuint vertexBufferObject;


        public:

        VertexBuffer(GLsizeiptr bufferSize);

        operator GLuint () const;

        GLvoid updateData(const GLvoid * bufferData) const;
};
