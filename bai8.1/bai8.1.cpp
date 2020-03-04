#include <iostream>
#include <glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include<GLAUX.H>
#pragma comment(lib,"legacy_stdio_definitions.lib")
int goc = 0;
GLuint g_box;                          // sử dụng để tạo display list cho đối tượng.
GLuint texture;                        // quản lý texture
char texture_name[100] = { "1.bmp" }; // lưu trữ tên file texture
AUX_RGBImageRec* LoadBMP(char* Filename)
{
	FILE* File = NULL;

	if (!Filename)
		return NULL;
	fopen_s(&File, Filename, "r");
	if (File)
	{
		fclose(File);
		return auxDIBImageLoadA((LPCSTR)Filename);
	}
	return NULL;
}
bool LoadGLTextures()
{
	int ret = false;
	AUX_RGBImageRec* texture_image = NULL;

	if (texture_image = LoadBMP(texture_name))
	{
		glGenTextures(1, &texture);  // Bắt đầu quá trình gen texture.
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//map dữ liệu bit map vào texture.
		glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image->sizeX,
			texture_image->sizeY, 0, GL_RGB,
			GL_UNSIGNED_BYTE, texture_image->data);
	}
	else
	{
		ret = false;
		if (texture_image)
		{
			if (texture_image->data)
				free(texture_image->data);
			free(texture_image);
		}
	}
	return ret;
}
GLuint MakeCube(const float& size)
{
	GLuint boxDisplay;
	boxDisplay = glGenLists(1);
	glNewList(boxDisplay, GL_COMPILE);

	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, size);
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, -size);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, -size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, size, size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -size);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -size, -size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(size, -size, -size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, size);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, -size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, size);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, -size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, -size);
	glEnd();

	glEndList();
	return boxDisplay;
}
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	LoadBMP(texture_name);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	
	LoadGLTextures();
	// Tạo một cube và load texture cho cube này (đang sử dụng cơ chế display list để render đối tượng)

	g_box = MakeCube(1.0);
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
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(15.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glRotatef(goc, 1, 0,0);
	glCallList(g_box);
	glFlush();
	goc = goc + 10;
	if (goc >= 360)
	{
		goc = 0;
	}
	glutPostRedisplay();
	Sleep(10);
}
void main()
{
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Opengl Study");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);

	glutMainLoop();

}