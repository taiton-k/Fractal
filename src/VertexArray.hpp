#pragma once

#include <GL/glew.h>


class VertexArray{
        private:

        GLuint vertexArrayObject;


        public:

        VertexArray();

        operator GLuint () const;

        GLvoid bindVertexBuffer(GLuint vertexBufferObject,GLsizeiptr datumSize,GLuint bindingIndex) const;

        GLvoid enableAttribute(GLuint attributeIndex,GLint dimension,GLenum typeName) const;

        GLvoid attributeBinding(GLuint attributeIndex,GLuint bindingIndex) const;
};
