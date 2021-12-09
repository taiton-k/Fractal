#include "VertexBuffer.hpp"


VertexBuffer::VertexBuffer(GLsizeiptr dataSize){

        glCreateBuffers(1,&vertexBufferObject);

        glNamedBufferData(vertexBufferObject,dataSize,NULL,GL_DYNAMIC_DRAW);


        return;
}

GLvoid VertexBuffer::updateData(const GLvoid * bufferData) const {
        GLint bufferSize;
        glGetNamedBufferParameteriv(vertexBufferObject,GL_BUFFER_SIZE,&bufferSize);

        glNamedBufferSubData(vertexBufferObject,0,bufferSize,bufferData);


        return;
}

VertexBuffer::operator GLuint () const {
        return vertexBufferObject;
}
