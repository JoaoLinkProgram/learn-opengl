#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"shaders/shader.hpp"
#include<iostream>

int main(){
    glfwInit();
    GLFWwindow* janela=glfwCreateWindow(400, 400, "janela", NULL, NULL);
    glfwMakeContextCurrent(janela);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    Shader shader;
    shader.create("shaders/vertex.glsl","shaders/fragment.glsl");
    std::cout<<shader.Linkprog;
    //create codenadas
    float _mesh_vertex[]={
        0.0f, 0.5f, 0.0f,
        -0.5f, 0.0f, 0.0f,
        0.5, 0.0f, 0.0f
    };
    // create o trianglo
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_mesh_vertex), _mesh_vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    shader.use();
    glGenBuffers(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    while(!glfwWindowShouldClose(janela)){
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        glBindVertexArray(VBO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(janela);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VBO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}