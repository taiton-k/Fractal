#pragma once

#include <iostream>

#include <GLFW/glfw3.h>


class Window{
        private :

        GLFWwindow * window;


        public :

        Window(int widgth,int height,const char * title);

        ~Window();

        operator GLFWwindow * () const;

        explicit operator bool () const;
};
