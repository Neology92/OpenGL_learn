#include <iostream>
// #include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

using namespace std;

int main(void)
{

	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}


	GLFWwindow *window = glfwCreateWindow(1000, 480, "So clear", NULL, NULL );

	if(!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	while(!glfwWindowShouldClose(window))
	{

		glClear(GL_COLOR_BUFFER_BIT);



		//Swap buffers and taking events
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

 	glfwTerminate();

 	exit(EXIT_SUCCESS);
}