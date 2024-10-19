#ifndef SHADERCLASS_H_
#define SHADERCLASS_H_

#include <glad/glad.h>
#include<fstream>
#include <string>
#include<sstream>
#include<iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);
class Shader{
    public:
        GLuint ID;
        Shader(const char* vertexFile, const char* fragmentFile);

        void Activate();
        void Delete();
};

#endif