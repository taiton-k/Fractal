#include <iostream>
#include <cstdlib>

#include "Window.hpp"

Window::Window(int widgth,int height,const char * title)
        : window(glfwCreateWindow(widgth,height,title,NULL,NULL)){
        if(window==NULL){
                std::cerr << "ウィンドウを作成できませんでした。" << std::endl;
                exit(-1);
        }
}

Window::~Window(){
        glfwDestroyWindow(window);
}

Window::operator GLFWwindow * () const {
        return window;
}

Window::operator bool () const {
        glfwSwapBuffers(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwWaitEvents();

        return glfwWindowShouldClose(window)==GLFW_FALSE;
}
