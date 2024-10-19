#ifndef VAO_H_
#define VAO_H_
#include <glad/glad.h>
#include <VBO.h>

class VAO{

public:
    GLuint ID;
    VAO();


    void linkVBO(VBO &VBO, GLuint layout);
    void Bind();
    void Unbind();
    void Delete();
};

#endif