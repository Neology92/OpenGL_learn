#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(void)
{
	// Init GLFW
	if (!glfwInit()){
		exit(EXIT_FAILURE);
		fprintf(stderr, "Err: GLFW!");
	}

	// Let's create window
	GLFWwindow *window = glfwCreateWindow(640, 480, "So clear", NULL, NULL );

	if(!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	// Init GLEW
	if (glewInit() != GLEW_OK){
		exit(EXIT_FAILURE);
		fprintf(stderr, "Err: GLEW!");
	}
	// glfwSwapInterval(1);


	float positions[6] = {
		-0.5, -0.5,
		 0.0,  0.5,
		 0.5, -0.5
	};
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW);

	// Window loop
	while(!glfwWindowShouldClose(window))
	{
		// Render
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		//Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();

	}

 	glfwTerminate();

 	exit(EXIT_SUCCESS);
}