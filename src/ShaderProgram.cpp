#include "ShaderProgram.hpp"


GLboolean ShaderProgram::isProgramLinkedSuccessfully() const {
        GLint linkStatus;
        glGetProgramiv(programObject,GL_LINK_STATUS,&linkStatus);
        return static_cast<GLboolean>(linkStatus);
}

GLvoid ShaderProgram::printProgramInfoLog() const {
        GLint programInfoLogLength;
        glGetProgramiv(programObject,GL_INFO_LOG_LENGTH,&programInfoLogLength);

        if(programInfoLogLength > 0){
                GLchar programInfoLog[static_cast<size_t>(programInfoLogLength)];
                glGetProgramInfoLog(programObject,static_cast<GLsizei>(programInfoLogLength),NULL,programInfoLog);
                std::cerr << "Link error in : " << programInfoLog << std::endl;
        }
}


ShaderProgram::ShaderProgram():programObject(glCreateProgram()){
        if(programObject==0){
                std::cerr << "glCreateProgram() Failed." << std::endl;
                std::exit(-1);
        }
}

ShaderProgram::operator GLuint () const {
        return programObject;
}

GLvoid ShaderProgram::attachShader(const GLuint &shader) const {
        glAttachShader(programObject,shader);
}

GLvoid ShaderProgram::link() const {
        glLinkProgram(programObject);

        if(isProgramLinkedSuccessfully() == GL_FALSE){
                std::cerr << "Failed to link the program object." << std::endl;

                printProgramInfoLog();

                std::exit(-1);
        }

        std::cout << "Program object linked successfully." << std::endl;
}
