// C program to demonstrate
// drawing a circle using
// OpenGL
#include <stdio.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2d(1,1);
        glVertex2d(0,0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("Line Drawing");

    glutDisplayFunc(display);
    glutMainLoop();
}
