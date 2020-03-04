// bai6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <gl\glut.h>

GLfloat g_box, g_box1, g_box2, g_box3, g_box4, g_box5;

void DrawCoordinate()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();
	glTranslatef(1.0, 0.0, 0.0);
	glEnable(GL_LIGHTING);
}
GLuint MakeCube(const float& size)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glBegin(GL_QUADS);
	// Front Face
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, size, -size);
	glEnd();
	glNormal3f(1.0, 0.0, 1.0);
	glTranslatef(-2.0, 0.0, 0.0);
	glEndList();
	return dp_list;
}
GLuint MakeBox(const float length, const float width, const float height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;
	//Back
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(0, y, 0);
	glEnd();

	// left
	glBegin(GL_QUADS);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(0, y, 0);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x, 0, z);
	glEnd();

	//// right
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x, 0, z);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glEnd();

	//Top
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, y, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glVertex3f(0, y, z);

	//Bottom
	glBegin(GL_QUADS);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, z);
	glVertex3f(0, 0, z);

	glEnd();
	glTranslatef(2.0, -1.0, 0.0);
	glEndList();

	return dp_list;
}
GLuint MakeSphere(const float& radius)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutSolidSphere(radius, 64, 64);
	glTranslatef(1.0, 2.0, 0.0);
	glEndList();

	return dp_list;
}
GLuint MakeCylinder(const float& radius, const float& length)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj* quadratic_obj;
	quadratic_obj = gluNewQuadric();
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic_obj, radius, radius, length, 50, 32);
	glTranslatef(3.0, 4.0, 0.0);
	glEndList();
	return dp_list;
}
GLuint MakeCone(const float& base_rad, const float& length)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj* quadratic_obj;
	quadratic_obj = gluNewQuadric();
	gluCylinder(quadratic_obj, base_rad, 0.0, length, 32, 50);
	glTranslatef(5.0, -2.0, 1.0);
	glEndList();

	return dp_list;
}

void RendenScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(5.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
	DrawCoordinate();
	glCallList(g_box);
	glCallList(g_box1);
	glCallList(g_box2);
	glCallList(g_box3);
	glCallList(g_box4);
	glPopMatrix();

	glFlush();
}

void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}


void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.5, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//g_box = MakeCube(1.0f);
	g_box1 = MakeBox(1.0f, 2.0f, 1.0f);
	g_box2 = MakeSphere(1.5f);
	g_box3 = MakeCylinder(1.5f, 1.0f);
	g_box4 = MakeCone(1.5f, 2.0f);

}

void main(int a, char** b)
{
	glutInit(&a, b);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Opengl Study");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RendenScene);

	glutMainLoop();

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
