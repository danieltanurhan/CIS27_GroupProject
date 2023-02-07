/**
* Program Name: displayFunction.c
* Discussion: OpenGL Display function definitions
* Written By: Daniel Tanurhan, Edwin Gutheru, Luca Mason
* Date: 2020/12/15
*/
#include "displayFunction.h"


void openGLSetUp(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Group 3 Project - Klotski");

	glutDisplayFunc(drawGrid);
	glColor3f(1.0, 0.0, 0.0);

	myinit();
	glutMainLoop();

}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}