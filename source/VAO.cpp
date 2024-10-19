#include "VAO.h"

VAO::VAO()
{
    // Generate the VAO and VBO with only 1 object each
    glGenVertexArrays(1, &ID);
}

void VAO::linkVBO(VBO &VBO, GLuint layout)
{
    VBO.Bind();
    // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VAO::Bind()
{
     // Make the VAO the current Vertex Array Object by binding it
    glBindVertexArray(this->ID);
}

void VAO::Unbind()
{
    // Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
    glBindVertexArray(0);
}

void VAO::Delete()
{
        glDeleteVertexArrays(1, &ID);
}
