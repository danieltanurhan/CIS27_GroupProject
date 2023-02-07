///**
//* Program Name: cis27Fall2020DanielTanurhan_FinalGroupProject_Update3_Individual.c
//* Discussion: Final Group Update #3 Individual
//* Written By: Daniel Tanurhan
//* Date: 2020/10/19, 2020/12/10
//*/
//
//#ifdef _MSC_VER                         
//#  pragma comment(lib, "opengl32.lib")  
//#  pragma comment(lib, "glu32.lib")     
//#  pragma comment(lib, "glut32.lib")     
//#endif
//
//#include<GL/glut.h>
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	glBegin(GL_POLYGON);
//	glColor3f(1.0, 0.6, 0.0);
//	glVertex2f(50.0, 50.0);
//	glVertex2f(150.0, 50.0);
//	glVertex2f(150.0, 150.0);
//	glVertex2f(50.0, 150.0);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex2f(300.0, 450.0);
//	glVertex2f(300.0, 400.0);
//	glVertex2f(400.0, 400.0);
//	glVertex2f(400.0, 450.0);
//	glEnd();
//
//
//	glFlush();
//}
//
//void myinitDanielT() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("CIS 27 Fall 2020 DT - Update 3 Individual");
//	glutDisplayFunc(display);
//
//	myinitDanielT();
//	glutMainLoop();
//	return 0;
//}