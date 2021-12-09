#include <iostream>
#include <cstdlib>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Utils.hpp"
#include "Window.hpp"
#include "ShaderProgram.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"

int main(void){

        initializeGLFW();

        std::atexit(glfwTerminate);


        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
        //glfwWindowHint(GLFW_DECORATED,GLFW_FALSE);
        //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER,GLFW_TRUE);
        //glfwWindowHint(GLFW_FLOATING,GLFW_TRUE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);

        // ウィンドウを作成する
        Window mainWindow(640,480,"Hello!");
        glfwMakeContextCurrent(mainWindow);

        initializeGLEW();

        glfwSwapInterval(1);

        glClearColor(0.0f,0.0f,0.0f,1.0f);

        Shader vertexShader(GL_VERTEX_SHADER,"glsl.vert");
        Shader fragmentShader(GL_FRAGMENT_SHADER,"glsl.frag");

        ShaderProgram program;
        program.attachShader(vertexShader);
        program.attachShader(fragmentShader);

        program.link();


        GLfloat verticies[4][2]={
                {1.0f,1.0f},
                {1.0f,-1.0f},
                {-1.0f,-1.0f},
                {-1.0f,1.0f}
        };

        VertexBuffer quad(sizeof(verticies));

        VertexArray array;

        array.enableAttribute(0,2,GL_FLOAT);
        array.bindVertexBuffer(quad,sizeof(GLfloat)*2,0);
        array.attributeBinding(0,0);

        while(mainWindow){
                glUseProgram(program);

                glBindVertexArray(array);

                quad.updateData(verticies);
                glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        }


        return  0;
}
