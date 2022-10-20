/*
*	GeometriaL.cpp
*	Codigo plantilla basico para dibujo de geometria
*	en modo inmediato y retenido
*
*	@author	r.vivo'
*/

// Bibliotecas de C++
#include <iostream>

// Bibliotecas graficas
#include <Utilidades.h>

using namespace std;
static float coordenadas[10];
static GLuint pentagono;

void init()
{
	const float radio = 1;
	for (auto i = 0; i < 10; i += 2) {
		coordenadas[i]   = radio * cosf(float(i) / 2 * 2 * PI / 5);
		coordenadas[i+1] = radio * sinf(float(i) / 2 * 2 * PI / 5);
	}

	pentagono = glGenLists(1);
	glNewList(pentagono, GL_COMPILE);
	glBegin(GL_POLYGON);
	for (auto i = 0; i < 10; i += 2) {
		glVertex3f(coordenadas[i], coordenadas[i + 1], 0);
	}
	glEnd();
	glEndList();

}

void display()
{
	// Callback de dibujo 
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 1, 0);
	glCallList(pentagono);

	// Renovar el dibujo
	glFlush();

}

void reshape(GLint w, GLint h)
{
	// w,h son las nuevas dimensiones de la ventana
}

int main(int argc, char** argv)
{
	// Inicializaciones
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(0, 0);

	// Crear la ventana
	glutCreateWindow("HOLA OpenGL");

	init();

	// Seccion de registrode callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	// Pone en marcha el bucle de atencion de evntos
	glutMainLoop();
}