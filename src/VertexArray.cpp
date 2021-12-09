#include "VertexArray.hpp"


VertexArray::VertexArray(){
        glCreateVertexArrays(1,&vertexArrayObject);

        return;
}

VertexArray::operator GLuint () const {
        return vertexArrayObject;
}

GLvoid VertexArray::bindVertexBuffer(GLuint vertexBufferObject,GLsizeiptr datumSize,GLuint bindingIndex) const {

        glVertexArrayVertexBuffer(vertexArrayObject,bindingIndex,vertexBufferObject,0,datumSize); 

        return;
}

GLvoid VertexArray::enableAttribute(GLuint attributeIndex,GLint dimension,GLenum typeName) const {

        glVertexArrayAttribFormat(vertexArrayObject,attributeIndex,dimension,typeName,GL_FALSE,0);

        glEnableVertexArrayAttrib(vertexArrayObject,attributeIndex);

        return;
}

GLvoid VertexArray::attributeBinding(GLuint attribIndex,GLuint bindingIndex) const {
        glVertexArrayAttribBinding(vertexArrayObject,attribIndex,bindingIndex);

        return;
}
