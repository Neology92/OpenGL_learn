#include <iostream>
// #include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

using namespace std;

void changeColors(float *r, float *g, float *b, bool *back, float push)
{
		if(*r <= 0.99 && !*back)
		*r += push;
		else if ( *g <= 0.99 && !*back)
		*g += push;
		else if ( *b <= 0.99 && !*back)
		*b += push;
		else
		{
			*back = 1;

			if (*r >= push)
			*r -= push;
			else if (*b >= push)
			*b -= push;
			else if (*g >= push)
			*g -= push;
			else
			{
				*back = 0;
			}
		}
		
		// cout << "R: " << *r << ", G: " << *g << ", B: " << *b << endl;
}

void moveAndBounce(float *x, float *y, float *s_x, float *s_y, float r, float ratio)
{

	
		if( *x + r > 1)
		{	
			*x = 0.999 - r;
			*s_x = -abs(*s_x);
		}	
		else if(*x - r < -1)
		{
			*x = -0.999 + r;
			*s_x = abs(*s_x);
		}

		if( (*y + r)*ratio > 1)
		{	
			// *y = 0.999 - r*ratio;
			*s_y = -abs(*s_y);
		}
		else if ((*y - r)*ratio < -1)
		{
			// *y = -0.999 + r;
			*s_y = abs(*s_y);

		}

	*x += *s_x;
	*y += *s_y;

	// if ((int)(*x*10) % 1 == 0)
	// cout << "X: " << *x << ",\t\tY: " << *y << ",\t\tSpeedX: " << *s_x << ",\t\tSpeedY: " << *s_y <<  endl;
}



int main(void)
{

	if (!glfwInit()){
		exit(EXIT_FAILURE);
	}

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow *window = glfwCreateWindow(640, 480, "Feakin' nice widows name!", NULL, NULL );

	if(!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	float radius = 0.1;

	// Colors of circle
	float r = 0.0;
	float g = 0.0;
	float b = 0.0;
	bool back = 0;

	// Colors of Square
	float rs = 0.0;
	float gs = 0.0;
	float bs = 0.0;
	bool back2 = 0;

	// Coordinates and movement
	float x = 0.0, y = 0.0;
	float speed_x = 0.007, speed_y = 0.009;

	while(!glfwWindowShouldClose(window))
	{
		//Get width and height
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		//Setup View
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		// myWhim about Colors
		changeColors(&r, &g, &b, &back, 0.01);

		// Some weird Modulo Stuff with Colors
		// r = fmod( r , 1);
		// g = fmod( g , 1);
		// b = fmod( b , 1);

		// Movement
		moveAndBounce(&x, &y, &speed_x, &speed_y, radius, ratio);

		//Draw
		
			//Koło
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
			for(int i = 0; i<=360; i++)
			{
				float angle = i * M_PI/180;
				glVertex2f(cos(angle)*radius+x, (sin(angle)*radius+y)*ratio);

				// Square 
				if(cos(angle)*radius+x > -0.3 && cos(angle)*radius+x < 0.3 
				&& sin(angle)*radius+y > -0.3 && sin(angle)*radius+y < 0.3)
				{
					changeColors(&rs, &gs, &bs, &back2, 0.0001);
				}

			}

		glEnd();

			//Square
		glColor3f(rs, gs, bs);
		glBegin(GL_QUADS);

			glVertex2f(-0.3,  0.3*ratio);
			glVertex2f(	0.3,  0.3*ratio);
			glVertex2f( 0.3, -0.3*ratio);
			glVertex2f(-0.3, -0.3*ratio);

		glEnd();

		//Swap buffers and taking events
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

 	glfwDestroyWindow(window);
 	glfwTerminate();

 	exit(EXIT_SUCCESS);
}