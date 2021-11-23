#include <iostream>
#include <cstdlib>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"

int main(void){

        // GLFWの初期化
        if(glfwInit() == GLFW_FALSE){
                std::cerr << "GLFWを初期化できませんでした。" << std::endl; 
                return -1;
        }

        std::atexit(glfwTerminate);


        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
        glfwWindowHint(GLFW_DECORATED,GLFW_FALSE);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER,GLFW_TRUE);
        //glfwWindowHint(GLFW_FLOATING,GLFW_TRUE);

        // ウィンドウを作成する
        Window main(640,480,"Hello!");

        //glfwWindowHint(GLFW_RESIZABLE,GLFW_TRUE);

        //Window sub(320,480,"Hello!");

        // ウィンドウをOpenGLの処理対象にする
        glfwMakeContextCurrent(main);

        glewExperimental = GL_TRUE;
        if(glewInit()!=GLEW_OK){
                std::cout << "GLEWの初期化に失敗しました。";
                return -1;
        }

        glClearColor(0.0f,0.0f,0.0f,0.0f);

        while(main){



                //
                // ここに描画処理
                //


                // フロントバッファとバックバッファを入れ替える

                // イベントを待つ
        }


        return  0;
}
