// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<GL/glut.h>
#include<GL/GLU.h>
#include<GL/GL.h>
#include <iostream>
float goc = 0;
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	glMatrixMode(GL_MODELVIEW);
}

void RenderScene()
{
	glClear(GL_COLOR_ARRAY_COUNT_EXT | GL_DEPTH_BUFFER_BIT);
	glRotatef(goc, 0.0, 1.0, 0.0);
	glutWireTeapot(2.0);
	glFlush();
	goc += 0.1;
	
	glutPostRedisplay();
}
int main(int argc, char** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Opengl Study");

	Init();
	
	glutReshapeFunc(ReShape);

	glutDisplayFunc(RenderScene);

	glutMainLoop();
	return 1;

	// std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
