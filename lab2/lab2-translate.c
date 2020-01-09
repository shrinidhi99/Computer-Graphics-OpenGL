#include <stdio.h>
#include <GL/glut.h>

GLfloat angle = 0.0f;

void initGL()
{
    glClearColor(0, 0, 0, 1);
}

void idle()
{
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x1 = 0, y1 = 0;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Triangle
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glRotatef(angle, 1, 0, 0);
    glTranslatef(0.0, -0.2, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1-0.1, y1);
        glVertex2f(x1+0.1, y1);
        glVertex2f(x1, y1+0.5);
    glEnd();
    glPopMatrix();

    // Pentagon 
    glPushMatrix();
    glTranslatef(0.5,0.2,0.0);
    glRotatef(angle, 0, 0, 0.5);
    glTranslatef(-0.5, -0.2, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.3, 0.2);
        glVertex2f(0.4, 0);
        glVertex2f(0.6, 0);
        glVertex2f(0.7, 0.2);
        glVertex2f(0.5, 0.3);
    glEnd();
    glPopMatrix();

    // Trapezium
    glPushMatrix();
    glTranslatef(-0.35, 0.1, 0.0);
    glRotatef(angle, 1, 0, -0.5);
    glTranslatef(0.35, -0.1, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, 0.2);
        glVertex2f(-0.6, 0);
        glVertex2f(-0.3, 0);
        glVertex2f(-0.4, 0.2);
    glEnd();

    glFlush();
    angle += 0.02;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    // initGL();
    // Giving name to window
    glutCreateWindow("Translate");
    glutIdleFunc(idle); // Register callback handler if no other event

    glutDisplayFunc(display);
    glutMainLoop();
}
