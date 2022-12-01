# include <iostream>
# include <glad/glad.h>
# include <GLFW/glfw3.h>

// TODO move everything to App class

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    // * init GLFW
    glfwInit();

    // * set OpenGL version (context)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // * use core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // * create window, handle failure
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // ? make context current on thread ?
    glfwMakeContextCurrent(window);

    // * initialize glad, handle failure
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // * tell GL we draw from 0,0 on 800*600
    glViewport(0, 0, 800, 600);

    // * place callbacks here
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // * render loop
    while(!glfwWindowShouldClose(window))
    {
        // * process input
        // ? why no key callbacks
        processInput(window);

        // * rendering commands
        glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // * swap back (render) and front (show) buffers
        glfwSwapBuffers(window);
        // * check for events ( window and input callbacks)
        glfwPollEvents();
    }

    // * clean exit
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // * resize viewport when screen is resized
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    // * manage input

    // * esc => close window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}