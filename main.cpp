#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(void)
{
	// Init GLFW
	if (!glfwInit()){
		exit(EXIT_FAILURE);
		fprintf(stderr, "Problem with GLFW!");
	}
	// Init GLEW
	if (glewInit()==GLEW_OK){
		exit(EXIT_FAILURE);
		fprintf(stderr, "Problem with GLEW!");
	}

	// Let's create window
	GLFWwindow *window = glfwCreateWindow(640, 480, "So clear", NULL, NULL );

	if(!window){
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