#version 450

layout (location = 0) in vec2 Pos;

void main(void){
        gl_Position = vec4(Pos,0.0,1.0);
}
