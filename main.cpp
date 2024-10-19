#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <math.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
// Vertices coordinates
GLfloat vertices[] =
    {
        -0.5f, -0.5f / 3, 0.0f,                 // Lower left corner
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
        0.0f, 0.5f * 2 / 3, 0.0f,               // Upper corner
        -0.5f / 2, 0.5f / 6, 0.0f,              // Inner left
        0.5f / 2, 0.5f / 6, 0.0f,               // Inner right
        0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f  // Inner down
};

// Indices for vertices order
GLuint indices[] =
    {
        5, 3, 0, // Lower left triangle

        4, 2, 3, // Upper triangle

        1, 4, 5 // Lower right triangle
};

int main()
{
    glfwInit();

    // Tell GLFW what version of OpenGL we are using
    // In this case we are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we are using the CORE profile
    // So that means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object of 800 by 800 pixels, naming it "FIrst try"
    GLFWwindow *window = glfwCreateWindow(900, 800, "FIrst try", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Window creation failed\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    gladLoadGL();
    // Specify the viewport of OpenGL in the Window
    // In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
    glViewport(0, 0, 800, 800);

    Shader shaderProgram("shaders/default.vert","shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices , sizeof(indices));

    VAO1.linkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    //Shows only the outline of shape
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Activate shader here         glUseProgram(shaderProgram);
        shaderProgram.Activate();

        VAO1.Bind();

        // glDrawArrays(GL_TRIANGLES, 1, 3);
        // glUseProgram(shaderProgramYellow);
        // glDrawArrays(GL_TRIANGLES, 3, 3);

        // Replacing this with another one to draw multiple one
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    // Delete shader here  glDeleteProgram(shaderProgram);
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}