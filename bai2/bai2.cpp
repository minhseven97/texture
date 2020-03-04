// bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include<GL/glut.h>


void DrawCoodinate()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(-100.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 100.0, 0.0);
	glVertex3f(0.0, -100.0, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 100.0);
	glVertex3f(0.0, 0.0, -100.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();
}


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.5, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawCoodinate();
	glPushMatrix();
	glTranslatef(-2.0, 0.0, 0.0);
	glRotatef(goc, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.5, 0.5);
	glutWireTeapot(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef(goc, 1.0, 3.0, 0.0);
	glColor3f(1.0, 0.0, 0.5);
	glutWireCone(0.1, 0.2, 16, 64);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glRotatef(goc, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.8, 0.3);
	glutWireTorus(0.05, 0.1, 16, 64);
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
	goc = goc + 10;
	if (goc >= 360)
	{
		goc = 0;
	}
	glutPostRedisplay();

	
}

void ReShape(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	float ratio = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, ratio, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}



void main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Phat Trien Phan Mem 123AZ");
	glutReshapeFunc(ReShape);// tính toán khi thay đổi cửa sổ
	glutDisplayFunc(RenderScene);
	glutMainLoop();// vòng lặp
}
