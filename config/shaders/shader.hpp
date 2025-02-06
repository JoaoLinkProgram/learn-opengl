#ifndef SHADER_HPP
#define SHADER_HPP
#include"../glad/glad.h"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
class Shader{
    public:
    unsigned int Linkprog;
    int create(const char* vertexPath, const char* fragmentPath){
        std::string vertexSource, fragmentSource;
        std::ifstream vertexFile;
        std::ifstream fragmentFile;
        vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        //open shaders
        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);
        //ler os arquivos do shaders
        std::stringstream vertexStream, fragmentStream;
        vertexStream<<vertexFile.rdbuf();
        fragmentStream<<fragmentFile.rdbuf();
        //fecha os arquivos
        vertexFile.close();
        fragmentFile.close();
        std::string vertexCode, fragmentCode;
        vertexCode=vertexStream.str();
        fragmentCode=fragmentStream.str();
        return Linkprog;
    }
    void use(){
        glUseProgram(Linkprog);
        std::cout<<Linkprog;
    }
};
#endif