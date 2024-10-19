#ifndef VBO_H_
#define VBO_H_
#include <glad/glad.h>

class VBO{
public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);

    void Bind();
    void Unbind();
    void Delete();
};

#endif