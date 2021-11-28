#include "Shader.hpp"


GLchar** Shader::loadShaderSource(const char *fileName){
        if(fileName==NULL){
                std::cerr << "Specified file name is NULL." << std::endl;
                std::exit(-1);
        }

        std::ifstream readFile(fileName,std::ios::in);

        if(readFile.fail()==true){
                std::cerr << "Failed to open the shader source file " << fileName << "." << std::endl;
                std::exit(-1);
        }


        readFile.seekg(0,std::ios::end);
        const auto charCount = readFile.tellg();

        std::unique_ptr<GLchar* []> shaderSource(new GLchar* [static_cast<size_t>(charCount) + 1]);

        readFile.seekg(0,std::ios::beg);

        readFile.read(*shaderSource.get(),charCount);

        if(readFile.fail()==true){
                std::cerr << "Failed to read the shader source file " << fileName << "." << std::endl;
                std::exit(-1);
        }

        *shaderSource[static_cast<size_t>(charCount)] = '\n';


        return shaderSource.get();
}

inline GLboolean Shader::isShaderCompiledSuccessfully() const {
        GLint compileStatus;
        glGetShaderiv(shaderObject,GL_COMPILE_STATUS,&compileStatus);
        return static_cast<GLboolean>(compileStatus);
}

inline GLvoid Shader::printShaderInfoLog() const {
        GLint shaderInfoLogLength;
        glGetShaderiv(shaderObject,GL_INFO_LOG_LENGTH,&shaderInfoLogLength);

        GLchar *shaderInfoLog=nullptr;
        glGetShaderInfoLog(shaderObject,static_cast<GLsizei>(shaderInfoLogLength),NULL,shaderInfoLog);
        std::cerr << "Compile error in : " << shaderInfoLog << std::endl;
}


Shader::Shader(const GLenum shaderType,const char *fileName):shaderObject(glCreateShader(shaderType)){
        if(shaderObject==0){
                std::cerr << "glCreateShader() Failed." << std::endl;
        }

        glShaderSource(shaderObject,1,loadShaderSource(fileName),NULL);
        std::cout << "Shader source file " << fileName << " loaded successfully." << std::endl;

        glCompileShader(shaderObject);

        if(isShaderCompiledSuccessfully() == GL_FALSE){
                std::cerr << "Failed to compile the shader source program " << fileName << " ." << std::endl;

                printShaderInfoLog();

                std::exit(-1);
        }

        std::cout << "Shader source program " << fileName << " compiled successfully." << std::endl;
}

GLenum Shader::shaderType() const {
        GLint shaderType;
        glGetShaderiv(shaderObject,GL_SHADER_TYPE,&shaderType);
        return static_cast<GLenum>(shaderType);
}

Shader::operator GLuint() const{
        return shaderObject;
}
